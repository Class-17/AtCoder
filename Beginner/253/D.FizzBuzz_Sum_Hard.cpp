#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    ll c = lcm(a, b);
    ll sum = (n + 1) * n / 2;
    ll ca = n / a, cb = n / b, cc = n / c;
    sum -= (ca + 1) * ca / 2 * a + (cb + 1) * cb / 2 * b;
    sum += (cc + 1) * cc / 2 * c;
    cout << sum << '\n';
    return 0;
}