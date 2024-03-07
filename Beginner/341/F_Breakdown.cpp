#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> w(n), a(n), id(n);
    for (auto &x : w) cin >> x;
    for (auto &x : a) cin >> x;
    iota(begin(id), end(id), 0);
    ranges::sort(id, {}, [&](const auto &x) {return w[x];});
    i64 res = 0;
    vector<int> dp(n);
    for (auto &u : id) {
        vector<int> bag(w[u]);
        for (auto &v : g[u])
            for (int i = w[u] - 1; i >= w[v]; --i)
                bag[i] = max(bag[i], bag[i - w[v]] + dp[v]);
        dp[u] = bag.back() + 1;
        res += 1LL * dp[u] * a[u];
    }
    cout << res << '\n';
    return 0;
}