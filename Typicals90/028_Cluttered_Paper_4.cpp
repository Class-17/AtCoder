#include <bits/stdc++.h>

constexpr int N = 1000;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    int a[N + 1][N + 1]{};
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1] += 1;
        a[x1][y2] -= 1;
        a[x2][y1] -= 1;
        a[x2][y2] += 1;
    }
    for (int i = 0; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            a[i][j] += a[i][j - 1];
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
            a[i][j] += a[i - 1][j];
    std::vector<int> res(n + 1);
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
                res[a[i][j]] += 1;
    for (int i = 1; i <= n; ++i)
        std::cout << res[i] << '\n';
    return 0;
}