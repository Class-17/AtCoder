#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> idx(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        idx[x].push_back(i);
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        int lo = lower_bound(begin(idx[x]), end(idx[x]), l) - begin(idx[x]);
        int hi = upper_bound(begin(idx[x]), end(idx[x]), r) - begin(idx[x]);
        cout << hi - lo << '\n';
    }
    return 0;
}