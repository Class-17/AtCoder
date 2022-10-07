#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> dp(m + 2, 1);
    for (int i = 1; i < n; ++i) {
        vector<ll> curr(m + 2);
        for (int j = 1; j <= m; ++j) {
            if (!dp[j]) continue;
            int lo = max(0, j - k), hi = min(m + 1, j + k);
            curr[1] = (curr[1] + dp[j]) % mod;
            curr[lo + 1] = (curr[lo + 1] - dp[j]) % mod + mod;
            if (hi == 1) continue;
            curr[hi] = (curr[hi] + dp[j]) % mod;
        }
        for (int j = 1; j <= m; ++j)
            curr[j] = (curr[j] + curr[j - 1]) % mod;
        dp = move(curr);
    }
    ll sum = 0;
    for (int i = 1; i <= m; ++i)
        sum = (sum + dp[i]) % mod;
    cout << sum << '\n';
    return 0;
}