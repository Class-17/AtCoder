#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 MOD = 1e8;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<i64> a(n + 1);
    for (auto &x : a) cin >> x;
    sort(begin(a), end(a));
    auto sum = a;
    partial_sum(begin(sum), end(sum), begin(sum));
    i64 res = 0;
    for (int i = 2; i <= n; ++i) {
        int j = lower_bound(begin(a), end(a), MOD - a[i]) - begin(a);
        res += sum[i - 1] + a[i] * (i - 1) - MOD * max(0, i - j); 
    }
    cout << res << '\n';
    return 0;
}