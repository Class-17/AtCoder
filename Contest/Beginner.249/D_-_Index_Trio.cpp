#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    sort(begin(arr), end(arr));
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll t = arr[i] * arr[j];
            if (t > arr.back()) break;
            auto l = lower_bound(begin(arr), end(arr), t);
            auto r = upper_bound(begin(arr), end(arr), t);
            if (*l == t) res += (r - l);
        }
    }
    cout << res << '\n';
    return 0;
}