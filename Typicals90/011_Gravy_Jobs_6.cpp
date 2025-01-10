#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5000;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::tuple<int, int, int>> jobs(n);
    for (auto &[d, c, s] : jobs)
        std::cin >> d >> c >> s;
    std::ranges::sort(jobs);
    std::vector<i64> dp(N + 1);
    for (auto &[d, c, s] : jobs)
        for (int i = d; i >= c; --i)
            dp[i] = std::max(dp[i], dp[i - c] + s);
    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}