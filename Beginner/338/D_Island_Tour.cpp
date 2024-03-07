#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> pos(m);
    for (auto &x : pos) cin >> x;
    vector<i64> diff(n * 2 + 1);
    i64 tot = 0;
    for (int i = 1; i < m; ++i) {
        int a = pos[i - 1], b = pos[i];
        if (a > b) swap(a, b);
        int x = (b - a);
        int y = n - (b - a);
        if (x <= y) {
            diff[a] += y - x;
            diff[b] -= y - x;
            tot += x;
        }
        else {
            diff[1] += x - y;
            diff[a] -= x - y;
            diff[b] += x - y;
            diff[n + 1] -= x - y;
            tot += y;
        }
    }
    partial_sum(begin(diff), end(diff), begin(diff));
    i64 extra = 1e14;
    for (int i = 1; i <= n; ++i)
        extra = min(extra, diff[i]);
    cout << tot + extra << '\n';
    return 0;
}