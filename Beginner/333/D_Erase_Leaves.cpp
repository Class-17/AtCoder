#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5;

vector<int> g[N+1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &dfs, int fa, int u)->int {
        int sum = 1;
        for (auto &v : g[u]) {
            if (v == fa) continue;
            sum += dfs(dfs, u, v);
        }
        return sum;
    };
    int res = 0;
    for (auto &v : g[1])
        res = max(res, dfs(dfs, 1, v));
    cout << n - res << '\n';
    return 0;
}