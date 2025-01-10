#include <bits/stdc++.h>

const double PI = std::acos(-1);

double p2(double x) {return x * x;}

double dist(double x1, double y1, double x2, double y2) {
    return std::sqrt(p2(x1 - x2) + p2(y1 - y2));
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t, l, x, y;
    std::cin >> t >> l >> x >> y;
    int q; std::cin >> q;
    while (q--) {
        double e; std::cin >> e;
        double z0 = (std::sin((e / t - 0.25) * PI * 2) + 1) * l / 2;
        double y0 = -std::cos((e / t - 0.25) * PI * 2) * l / 2;
        double res = std::atan2(z0, dist(0, y0, x, y)) * 180 / PI;
        std::cout << std::setprecision(12) << std::fixed << res << '\n';
    }
    return 0;
}