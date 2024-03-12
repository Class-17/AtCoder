#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    list<int> lst;
    map<int, list<int>::iterator> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        mp[x] = lst.insert(end(lst), x);
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            mp[y] = lst.insert(next(mp[x]), y);
        }
        else {
            int x; cin >> x;
            lst.erase(mp[x]);
            mp.erase(x);
        }
    }
    for (auto it = begin(lst); it != end(lst); ++it)
        cout << *it << " \n"[next(it) == end(lst)];
    return 0;
}