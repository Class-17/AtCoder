#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, r;
    std::cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int d, a;
        std::cin >> d >> a;
        if (d == 1 and 1600 <= r and r <= 2799)
            r += a;
        if (d == 2 and 1200 <= r and r <= 2399)
            r += a;
    }
    std::cout << r << '\n';
    return 0;
}