#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int invn = quick_pow(n, MOD - 2);
    i64 p = invn, res = 0;
    for (int i = 0; i < n; ++i) {
        i64 x; cin >> x;
        res = (res + p * x) % MOD;
        p = (p + p * invn) % MOD;
    }
    cout << res << '\n';
    return 0;
}