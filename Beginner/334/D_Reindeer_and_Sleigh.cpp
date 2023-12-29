#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<i64> arr(n);
    for (auto &x : arr) cin >> x;
    sort(begin(arr), end(arr));
    partial_sum(begin(arr), end(arr), begin(arr));
    for (int i = 0; i < q; ++i) {
        i64 x; cin >> x;
        auto p = upper_bound(begin(arr), end(arr), x) - begin(arr);
        cout << p << '\n';
    }
    return 0;
}