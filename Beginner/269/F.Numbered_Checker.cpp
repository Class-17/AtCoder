#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

ll count(ll a, ll b, ll c, ll d, ll minus) {
    ll res = (c + d + minus * 2) * (d - c + 1) / 2 % mod * ((b - a + 1) / 2) % mod;
    if ((b - a + 1) % 2 == 0) return res;
    if ((c + a) % 2) ++c;
    if ((d + b) % 2) --d;
    if (c > d) return res;
    ll add = (c + d + minus * 2) * ((d - c + 2) / 2) / 2 % mod;
    res = (res + add) % mod;
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll row = count(c, d, a, b, -1) * m % mod;
        ll col = count(a, b, c, d, 0);
        cout << (row + col) % mod << '\n';
    }
    return 0;
}