#include <bits/stdc++.h>

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};
const std::string S = "RDLU";

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    --x, --y;
    std::vector<std::string> grid(n);
    for (auto &row : grid) std::cin >> row;
    std::string t; std::cin >> t;
    int res = 0;
    for (auto &c : t) {
        const auto &[dx, dy] = dirs[S.find(c)];
        int nx = x + dx, ny = y + dy;
        if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
        if (grid[nx][ny] == '#') continue;
        res += grid[nx][ny] == '@';
        grid[nx][ny] = '.';
        x = nx, y = ny;
    }
    std::cout << x + 1 << ' ' << y + 1 << ' ' << res << '\n';
    return 0;
}