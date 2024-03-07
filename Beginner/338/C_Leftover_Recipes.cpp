#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> q(n), a(n), b(n);
    for (auto &x : q) cin >> x;
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int res = 0;
    auto count = [&](int c)->int {
        int cur = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] * c > q[i]) return 0;
            if (b[i] == 0) continue;
            int r = q[i] - a[i] * c;
            cur = min(cur, r / b[i]);
        }
        return c + cur;;
    };
    for (int i = 0; i <= q[0] / max(a[0], 1); ++i)
        res = max(res, count(i));
    cout << res << '\n';
    return 0;
}