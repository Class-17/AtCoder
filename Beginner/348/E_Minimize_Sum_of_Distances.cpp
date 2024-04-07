#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<i64> c(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    vector<i64> dp(n + 1), res(n + 1);
    auto pre_dfs = [&](auto &f, int fa, int u)->void {
        dp[u] = c[u];
        for (auto &v : g[u]) {
            if (v == fa) continue;
            f(f, u, v);
            dp[u] += dp[v];
            res[u] += res[v] + dp[v];
        }
    };
    pre_dfs(pre_dfs, 1, 1);
    auto dfs = [&](auto &f, int fa, int u)->void {
        if (fa != u)
            res[u] = res[fa] - (res[u] + dp[u]) + (dp[1] - dp[u]) + res[u];
        for (auto &v : g[u]) {
            if (v == fa) continue;
            f(f, u, v);
        } 
    };
    dfs(dfs, 1, 1);
    cout << *min_element(begin(res) + 1, end(res)) << '\n';
    return 0;
}