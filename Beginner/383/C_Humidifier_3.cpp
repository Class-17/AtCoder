#include <bits/stdc++.h>

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<std::string> grid(n);
    for (auto &x : grid) std::cin >> x;
    std::queue<std::tuple<int, int, int>> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 'H')
                q.emplace(i, j, d);
    int res = q.size();
    while (!q.empty()) {
        auto [r, c, k] = q.front(); q.pop();
        if (k == 0) continue;
        for (auto &[dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
            if (grid[nr][nc] != '.') continue;
            grid[nr][nc] = '#';
            q.emplace(nr, nc, k - 1);
            res += 1;
        }
    }
    std::cout << res << '\n';
    return 0;
}