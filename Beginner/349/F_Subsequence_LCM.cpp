#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

vector<pair<i64, i64>> prime_factor(i64 x) {
    vector<pair<i64, i64>> factors;
    for (i64 i = 2; i * i <= x; ++i) {
        i64 c = 0;
        while (x % i == 0) {
            x /= i;
            ++c;
        }
        if (c == 0) continue;
        factors.emplace_back(i, c);
    }
    if (x > 1)
        factors.emplace_back(x, 1);
    return factors;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, m;
    cin >> n >> m;
    vector<i64> arr(n);
    for (auto &x : arr) cin >> x;
    auto factors = prime_factor(m);
    int len = size(factors);
    vector dp(1 << len, 0);
    dp[0] = 1;
    map<i64, i64> mp;
    for (auto &x : arr) {
        if (m % x != 0) continue;
        int mask = 0;
        for (int i = 0; i < len; ++i) {
            const auto &[v, cnt] = factors[i];
            int c = 0;
            while (x % v == 0) {
                x /= v;
                ++c;
            }
            if (c == cnt)
                mask |= 1 << i;
        }
        mp[mask]++;
    }
    vector<int> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = pow2[i-1] * 2LL % MOD;
    for (auto &[mask, v] : mp)
        for (int i = (1 << len) - 1; i >= 0; --i)
            dp[i|mask] = (dp[i|mask] + dp[i] * (pow2[v] - 1LL)) % MOD;
    if (m == 1) --dp[(1 << len) - 1];
    cout << dp[(1 << len) - 1] << '\n';
    return 0;
}