#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

i64 quick_pow(i64 x, i64 n) {
    x %= MOD;
    i64 res = 1;
    while (n) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

i64 divide(i64 x, i64 n) {
    if (n == 1) return x % MOD;
    i64 len = size(to_string(x));
    i64 half = divide(x, n / 2);
    i64 res = half * quick_pow(10, len * n / 2 ) % MOD + half;
    res %= MOD;
    if (n & 1) {
        res += (x % MOD) * quick_pow(10, len * (n - 1)) % MOD;
        res %= MOD;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; cin >> n;
    i64 res = divide(n % MOD, n);
    cout << res << '\n';
    return 0;
}