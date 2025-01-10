#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int k; std::cin >> k;
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size(), m = t.size();
    if (std::abs(n - m) > k) {
        std::cout << "No\n";
        return 0;
    }
    std::vector dp(n + 1, std::vector(k * 2 + 1, k + 1));
    for (int i = 0; i <= k * 2; ++i)
        dp[0][i] = std::abs(i - k);
    s = '#' + s;
    t = '#' + t;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - k; j <= i + k; ++j) {
            if (j < 0 or j > m) continue;
            int d = j - (i - k);
            if (d - 1 >= 0)
                dp[i][d] = std::min(dp[i][d], dp[i][d - 1] + 1);
            if (d + 1 <= k * 2)
                dp[i][d] = std::min(dp[i][d], dp[i - 1][d + 1] + 1);
            dp[i][d] = std::min(dp[i][d], dp[i - 1][d] + (s[i] != t[j]));
        }
    }
    std::cout << (dp[n][m - (n - k)] <= k ? "Yes" : "No") << '\n';
    return 0;
}