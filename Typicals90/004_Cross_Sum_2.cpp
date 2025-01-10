#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector(m, 0));
    for (auto &row : a) for (auto &x : row)
        std::cin >> x;
    std::vector<int> row(n), col(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cout << row[i] + col[j] - a[i][j] << " \n"[j + 1 == m];
    return 0;
}