#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;
        if (mp.contains(c))
            mp[c] = min(mp[c], a);
        else
            mp[c] = a;
    }
    int res = 0;
    for (auto &[k, v] : mp)
        res = max(res, v);
    cout << res << '\n';
    return 0;
}