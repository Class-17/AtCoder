#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    vector<ll> a(n), b(n);
    a[0] = min(arr[0], l);
    for (int i = 1; i < n; ++i)
        a[i] = min(a[i - 1] + arr[i], l * (i + 1));
    b[n - 1] = min(arr[n - 1], r);
    for (int i = n - 2; i >= 0; --i)
        b[i] = min(b[i + 1] + arr[i], r * (n - i));
    ll res = min(a.back(), b.front());
    for (int i = 0; i + 1 < n; ++i)
        res = min(res, a[i] + b[i + 1]);
    cout << res << '\n';
    return 0;
}