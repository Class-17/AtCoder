#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    ll res = accumulate(begin(arr), end(arr), 0LL);
    if (n & 1 ^ 1) {
        ll x = 0, y = 0;
        for (int i = 0; i + 1 < n; i += 2)
            x += arr[i], y += arr[i + 1];
        res = min({res, x, y});
    }
    else {
        vector<int> a(n * 2), b(n * 2);
        for (int i = 0; i < n; i += 2)
            a[i] = arr[i] + (i > 1 ? a[i - 2] : 0);
        for (int i = 1; i < n; i += 2)
            b[i] = arr[i] + (i > 1 ? b[i - 2] : 0);
        for (int i = n; i < n * 2; ++i) {
            a[i] = a[n - 1];
            b[i] = b[n - 2];
        }
        for (int i = 0; i < n; ++i) {
            ll xl = (i & 1 ? (i > 0 ? a[i - 1] : 0) : (i > 1 ? a[i - 2] : 0));
            ll yl = (i & 1 ? (i > 1 ? b[i - 2] : 0) : (i > 0 ? b[i - 1] : 0));
            ll xr = (i & 1 ? (i > 0 ? a[i + 1] - a[i - 1] : a[i + 1]) : (i > 1 ? a[i + 2] - a[i - 2] : a[i + 2]));
            ll yr = (i & 1 ? (i > 1 ? b[i + 2] - b[i - 2] : b[i + 2]) : (i > 1 ? b[i + 1] - b[i - 1] : b[i + 1]));
            ll x = min(xl, yl), y = min(xr, yr);
            res = min({res, x + arr[i] + y});
        }
    }
    cout << res << '\n';
    return 0;
}