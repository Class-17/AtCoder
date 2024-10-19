#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::string> grid(n);
    for (auto &row : grid) std::cin >> row; 
    auto ret = grid;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int d = std::min({i + 1, j + 1, n - i, n - j});
            int x = i, y = j;
            for (int i = 0; i < d % 4; ++i)
                std::tie(x, y) = std::pair{y, n - 1 - x};
            ret[x][y] = grid[i][j];
        }
    for (auto &row : ret)
        std::cout << row << '\n';
    return 0;
}