#include <bits/stdc++.h>
#include <atcoder/all>

using mint = atcoder::modint1000000007;

const std::string S = "#atcoder";

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<mint> dp(S.size());
    dp[0] = 1;
    for (auto &c : s) {
        auto p = S.find(c);
        if (p == std::string::npos) continue;
        dp[p] += dp[p - 1];
    }
    std::cout << dp.back().val() << '\n';
    return 0;
}