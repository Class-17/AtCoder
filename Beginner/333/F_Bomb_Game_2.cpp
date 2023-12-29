#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

using i64 = long long;

constexpr int N = 3000;

i64 quick_pow(i64 x, i64 n) {
    i64 res = 1;
    while (n) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

i64 dp[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    dp[0][n-1] = 1;
    for (int len = n - 1; len > 0; --len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            if (j + 1 < n)
                dp[i][j] = dp[i][j+1] * quick_pow(2, MOD - 2) % MOD;
            if (i - 1 >= 0)
                dp[i][j] = dp[i-1][j] * quick_pow(2, MOD - 2) % MOD;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << dp[i][i] << " \n"[i + 1 == n];
    return 0;
}