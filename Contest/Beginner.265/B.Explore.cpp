#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> arr(n - 1);
    for (auto &x : arr) cin >> x;
    vector<ll> bonus(n - 1);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        bonus[x - 1] = y;
    }
    auto check = [&]() {
        for (int i = 0; i < n - 1; ++i) {
            t += bonus[i];
            t -= arr[i];
            if (t <= 0) return false;
        }
        return true;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}