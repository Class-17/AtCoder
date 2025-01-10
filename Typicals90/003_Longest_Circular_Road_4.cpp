#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto bfs = [&](int s) {
        std::queue<int> q;
        std::vector<int> dist(n, -1);
        q.push(s);
        dist[s] = 0;
        int res = 0;
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            res = u;
            for (auto &v : g[u]) {
                if (dist[v] >= 0) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        return std::pair{res, dist[res]};
    };
    auto [e1, d1] = bfs(0);
    auto [e2, d2] = bfs(e1);
    std::cout << d2 + 1 << '\n';
    return 0;
}