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
    for (int i = 0, j = 1e6; i <= 1e6 && i <= j; ++i)
        while (f(i, j) >= n && j >= i)
            x = min(x, f(i, j--));
    cout << x << '\n';
    return 0;
}