#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::vector<double> prob(n + 1);
    prob[0] = 1.0;
    for (int i = 0; i < n; ++i) {
        std::vector<double> dp(n + 1);
        for (int j = 0; j <= n; ++j) {
            if (j + 1 <= n)
                dp[j + 1] += prob[j] * a[i] / 100;
            dp[j] += prob[j] * (100 - a[i]) / 100;
        }
        prob = std::move(dp);
    }
    std::vector<double> dp(k + 1);
    for (int i = 1; i <= k; ++i) {
        dp[i] = 1.0;
        for (int j = 1; j <= std::min(n, i); ++j)
            dp[i] += prob[j] * dp[i - j];
        dp[i] /= 1.0 - prob[0];
    }
    std::cout << std::setprecision(16) << std::fixed << dp[k] << '\n';
    return 0;
}