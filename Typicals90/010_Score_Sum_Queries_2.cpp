#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector sum(3, std::vector(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        int c, p;
        std::cin >> c >> p;
        sum[c][i] = p;
    }
    for (auto &a : sum)
        std::partial_sum(a.begin(), a.end(), a.begin());
    int q; std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << sum[1][r] - sum[1][l - 1] << " ";
        std::cout << sum[2][r] - sum[2][l - 1] << "\n";
    }
    return 0;
}