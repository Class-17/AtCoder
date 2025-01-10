#include <bits/stdc++.h>

int dist(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<std::string> grid(n);
    for (auto &x : grid) std::cin >> x;
    int res = 0;
    for (int x1 = 0; x1 < n; ++x1)
        for (int y1 = 0; y1 < m; ++y1)
            for (int x2 = 0; x2 < n; ++x2)
                for (int y2 = 0; y2 < m; ++y2) {
                    if (grid[x1][y1] == '#' or grid[x2][y2] == '#') continue;
                    int cnt = 0;
                    for (int r = 0; r < n; ++r)
                        for (int c = 0; c < m; ++c) if (grid[r][c] == '.')
                            if (std::min(dist(r, c, x1, y1), dist(r, c, x2, y2)) <= d)
                                cnt += 1;
                    res = std::max(res, cnt);
                }
    std::cout << res << '\n';
    return 0;
}