#include <bits/stdc++.h>

struct Edge {
    int v, w;
    bool operator < (const Edge &other) const {
        return w > other.w;
    }
};

std::vector<int> dijkstra(const auto &g, int s) {
    int n = g.size();
    std::vector<int> dist(n, 1e9);
    dist[s] = 0;
    std::priority_queue<Edge> pq;
    pq.emplace(s, 0);
    while (!pq.empty()) {
        auto [u, d] = pq.top(); pq.pop();
        if (d < dist[u]) continue;
        for (auto &[v, w] : g[u]) {
            if (dist[v] <= d + w) continue;
            dist[v] = d + w;
            pq.emplace(v, dist[v]);
        }
    }
    return dist;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<Edge>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    auto d1 = dijkstra(g, 0);
    auto d2 = dijkstra(g, n - 1);
    for (int i = 0; i < n; ++i)
        std::cout << d1[i] + d2[i] << '\n';
    return 0;
}