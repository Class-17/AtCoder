#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> grid(n);
    for (auto &row : grid) std::cin >> row;
    auto dfs = [&](auto &dfs, int r, int c, int cnt) {
        if (cnt == 0) return 1;
        grid[r][c] = '#';
        int res = 0;
        for (auto &[dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
            if (grid[nr][nc] == '#') continue;
            res += dfs(dfs, nr, nc, cnt - 1);
        }
        grid[r][c] = '.';
        return res;
    };
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') continue;
            res += dfs(dfs, i, j, k);
        }
    std::cout << res << '\n';
    return 0;
}