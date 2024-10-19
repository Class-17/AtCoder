#include <bits/stdc++.h>

double dist(int x1, int y1, int x2, int y2) {
    return std::sqrt(1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2));
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    double res = 0;
    int x0 = 0, y0 = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        res += dist(x0, y0, x, y);
        x0 = x, y0 = y;
    }
    res += dist(x0, y0, 0, 0);
    std::cout << std::setprecision(9) << std::fixed << res << '\n';
    return 0;
}