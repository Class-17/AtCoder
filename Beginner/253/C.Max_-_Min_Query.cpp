#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<int, int> mp;
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            ++mp[x];
        }
        else if (t == 2) {
            int x, c; cin >> x >> c;
            int minus = min(c, mp[x]);
            mp[x] -= minus;
            if (mp[x] == 0) mp.erase(x);
        }
        else {
            int lo = begin(mp)->first, hi = rbegin(mp)->first;
            cout << hi - lo << '\n';
        }
    }
    return 0;
}