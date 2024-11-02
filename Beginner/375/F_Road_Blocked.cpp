#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 300;
constexpr i64 INF = 1e12;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector dist(n, std::vector(n, INF));
    std::vector<std::tuple<int, int, int>> es(m);
    for (auto &[u, v, w] : es)
        std::cin >> u >> v >> w, --u, --v;
    std::vector<std::tuple<int, int, int>> queries(q);
    std::vector<int> st(m);
    for (auto &[t1, t2, t3] : queries) {
        std::cin >> t1;
        if (t1 == 1) {
            std::cin >> t2, --t2;
            st[t2] = 1;
        }
        else
            std::cin >> t2 >> t3, --t2, --t3;
    }
    for (int i = 0; auto &[u, v, w] : es) {
        if (st[i] == 0)
            dist[u][v] = dist[v][u] = w;
        i += 1;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
    std::vector<i64> res;
    for (auto &[t1, t2, t3] : queries | std::views::reverse) {
        if (t1 == 1) {
            auto [u, v, w] = es[t2];
            if (w >= dist[u][v]) continue;
            dist[u][v] = dist[v][u] = w;
            for (auto &k : {u, v})
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        else {
            res.push_back(dist[t2][t3]);
        }
    }
    for (auto &x : res | std::views::reverse)
        std::cout << (x < INF ? x : -1) << '\n';
    return 0;
}