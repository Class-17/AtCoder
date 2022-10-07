#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll f(ll a, ll b) {
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n; cin >> n;
    ll x = LLONG_MAX;
    for (int a = 0; a <= 1e6; ++a) {
        ll lo = 0, hi = 1e6;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (f(a, mid) < n) lo = mid + 1;
            else               hi = mid;
        }
        if (f(a, lo) >= n) x = min(x, f(a, lo));
    }
    cout << x << '\n';
    return 0;
}