#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n; cin >> n;
    cout << ((n + mod) % mod + mod) % mod << '\n';
    return 0;
}