#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<i64> dp(n), sz(n, 1), res(n);
    auto dfs = [&](auto &self, int fa, int u)->void {
        for (auto &v : g[u]) {
            if (v == fa) continue;
            self(self, u, v);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    };
    auto reroot = [&](auto &self, int fa, int u)->void {
        for (auto &v : g[u]) {
            if (v == fa) continue;
            res[v] = dp[v] + (res[u] - (dp[v] + sz[v])) + (n - sz[v]);
            self(self, u, v);
        }
    };
    dfs(dfs, 0, 0);
    res[0] = dp[0];
    reroot(reroot, 0, 0);
    std::cout << std::accumulate(res.begin(), res.end(), 0LL) / 2 << '\n';
    return 0;
}