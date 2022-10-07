#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    ll res = LLONG_MAX, accu = 0;
    for (int i = 0; i < n and i < m; ++i) {
        accu += a[i] + b[i];
        res = min(res, accu + (m - i - 1) * b[i]);
    }
    cout << res << '\n';
    return 0;
}