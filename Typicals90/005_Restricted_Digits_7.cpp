#include <bits/stdc++.h>
#include <atcoder/all>

using mint = atcoder::modint1000000007;
using i64 = long long;

constexpr int N = 60;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, b, k;
    std::cin >> n >> b >> k;
    int pow10[N]{10};
    for (int i = 1; i < N; ++i)
        pow10[i] = (pow10[i - 1] * pow10[i - 1]) % b;
    std::vector dp(N, std::vector<mint>(b));
    for (int i = 0; i < k; ++i) {
        int c; std::cin >> c;
        dp[0][c % b] += 1;
    }
    for (int i = 1; i < N; ++i) {
        auto &pre = dp[i - 1], &cur = dp[i];
        for (int x = 0; x < b; ++x)
            for (int y = 0; y < b; ++y)
                cur[(x * pow10[i - 1] + y) % b] += pre[x] * pre[y];
    }
    std::vector<mint> res(b);
    res[0] = 1;
    for (int i = 0; i < N; ++i) if (n >> i & 1) {
        std::vector<mint> cur(b);
        for (int x = 0; x < b; ++x)
            for (int y = 0; y < b; ++y)
                cur[(x * pow10[i] + y) % b] += res[x] * dp[i][y];
        res = std::move(cur);
    }
    std::cout << res[0].val() << '\n';
    return 0;
}