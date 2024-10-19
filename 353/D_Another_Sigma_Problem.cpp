#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

i64 basePower(i64 n) {
    if (n == 0) return 1;
    return basePower(n - 1) * 10 % MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;
    i64 res = 0, preSum = 0;
    for (int i = 0; i < n; ++i) {
        i64 power = basePower(size(to_string(a[i])));
        res += preSum * power % MOD + a[i] * i;
        res %= MOD;
        preSum += a[i];
        preSum %= MOD;
    }
    cout << res << '\n';
    return 0;
}