#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, x, k;
    std::cin >> n >> x >> k;
    std::vector<std::vector<std::pair<int, int>>> products(n + 1);
    for (int i = 1; i <= n; ++i) {
        int p, u, c;
        std::cin >> p >> u >> c;
        products[c].emplace_back(p, u);
    }
    std::vector<i64> dp(x + 1);
    for (int i = 1; i <= n; ++i) {
        auto ndp = dp;
        for (auto &[p, u] : products[i]) {
            for (int j = x; j >= p; --j) {
                ndp[j] = std::max(ndp[j], dp[j - p] + u + k);
                ndp[j] = std::max(ndp[j], ndp[j - p] + u);
            }
        dp = std::move(ndp);
    }
    std::cout << dp[x] << '\n';
    return 0;
}