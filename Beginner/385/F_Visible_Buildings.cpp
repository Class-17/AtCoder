#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<long double> x(n), h(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> h[i];
    long double res = -1;
    for (int i = 0; i + 1 < n; ++i) {
        long double a = x[i] * h[i + 1] - x[i + 1] * h[i];
        long double b = x[i] - x[i + 1];
        res = std::max(res, a / b);
    }
    if (res < 0)
        std::cout << -1 << '\n';
    else
        std::cout << std::fixed << std::setprecision(18) << res;
    return 0;
}