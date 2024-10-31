#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    std::vector<int> adjs;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u - 1].push_back(v - 1);
        if (v - 1 == 0) adjs.push_back(u - 1);
    }
    std::vector<int> dist(n, -1);
    std::queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto &v : g[u]) {
            if (dist[v] != -1) continue;
            q.push(v);
            dist[v] = dist[u] + 1;
        }
    }
    int res = n;
    for (auto &u : adjs) {
        if (dist[u] == -1) continue;
        res = std::min(res, dist[u]);
    }
    std::cout << (res < n ? res + 1 : -1) << '\n';
    return 0;
}