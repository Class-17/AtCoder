#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<int> a(n * 2);
    for (auto &x : a) std::cin >> x;
    std::vector dp(n * 2 + 1, std::vector(n * 2 + 1, 0));
    for (int i = 2; i <= n * 2; i += 2)
        for (int l = 0; l + i <= n * 2; l += 1) {
            int r = l + i;
            dp[l][r] = dp[l + 1][r - 1] + std::abs(a[l] - a[r - 1]);
            for (int k = l + 2; k + 2 <= r; k += 2)
                dp[l][r] = std::min(dp[l][r], dp[l][k] + dp[k][r]);
        }
    std::cout << dp[0][n * 2] << '\n';
    return 0;
}