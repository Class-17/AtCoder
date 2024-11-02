#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n; cin >> n;
    vector<int> bits;
    for (int i = 0; i < 60; ++i)
        if (n >> i & 1) bits.push_back(i);
    int len = size(bits);
    for (int i = 0; i < (1 << len); ++i) {
        ll x = 0;
        for (int j = 0; j < len; ++j)
            if (i >> j & 1)
                x |= 1LL << bits[j];
        cout << x << '\n';
    }
    return 0;
}