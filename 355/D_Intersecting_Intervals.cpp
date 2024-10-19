#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> itv(n);
    for (auto &[l, r] : itv)
        cin >> l >> r;
    ranges::sort(itv);
    i64 res = 0;
    for (int i = 0; i < n; ++i) {
        auto &[l, r] = itv[i];
        int lo = i, hi = n;
        while (lo < hi) {
            int mid = lo + hi >> 1;
            if (itv[mid].first <= r)
                lo = mid + 1;
            else
                hi = mid;
        }
        res += lo - i - 1;
    }
    cout << res << '\n';
    return 0;
}