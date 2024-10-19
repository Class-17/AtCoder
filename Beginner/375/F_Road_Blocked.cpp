#include <bits/stdc++.h>

constexpr int N = 300;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    std::cin >> n >> m >> q;
    int dist[N][N]{};
    memset(dist, 0x3f, sizeof dist);
    std::vector<std::tuple<int, int, int>> es(m);
    for (auto &[u, v, w] : es)
        std::cin >> u >> v >> w;
    std::vector<std::tuple<int, int, int>> querys(q);
    std::vector<int> st(m);
    for (auto &[t1, t2, t3] : querys) {
        std::cin >> t2 >> t2;
        if (t1 == 1)
            st[t2 - 1] = 1;
        else
            std::cin >> t3;
    }
    for (auto &[t1, t2, t3] : std::views::reverse | querys) {

    }
    return 0;
}