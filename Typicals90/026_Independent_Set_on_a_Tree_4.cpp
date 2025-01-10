#include <bits/stdc++.h>

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
    std::vector<int> color(n);
    auto dfs = [&](auto &self, int fa, int u)->void {
        color[u] = color[fa] ^ 1;
        for (auto &v : g[u])
            if (v != fa) self(self, u, v);
    };
    dfs(dfs, 0, 0);
    int t = std::count(color.begin(), color.end(), 1) >= n / 2;
    for (int i = 0, j = 0; i < n and j < n / 2; ++i)
        if (color[i] == t) {
            std::cout << i + 1 << " \n"[j + 1 == n / 2];
            j += 1;
        }
    return 0;
}