#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, w, m;
    cin >> h >> w >> m;
    set<int> row, col;
    map<int, i64> cnt;
    vector<tuple<int, int, int>> paint(m);
    for (auto &[t, a, x] : paint)
        cin >> t >> a >> x;
    reverse(begin(paint), end(paint));
    for (auto &[t, a, x] : paint) {
        if (t == 1) {
            if (row.count(a) or size(col) == w)
                continue;
            cnt[x] += w - size(col);
            row.insert(a);
        }
        else {
            if (col.count(a) or size(row) == h)
                continue;
            cnt[x] += h - size(row);
            col.insert(a);
        }
    }
    i64 sum = 1LL * h * w;
    for (auto &[k, v] : cnt)
        sum -= v;
    if (sum > 0) cnt[0] += sum;
    cout << size(cnt) << '\n';
    for (auto &[k, v] : cnt)
        cout << k << ' ' << v << '\n';
    return 0;
}