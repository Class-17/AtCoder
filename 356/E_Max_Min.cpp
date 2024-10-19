#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;
    sort(begin(a), end(a));
    i64 res = 0, prevSum = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (i > 0 and a[i] == a[i - 1]) {
            res += --prevSum;
            continue;
        }
        i64 j = i + 1, p = a[i + 1] / a[i], sum = 0;
        do {
            int k = lower_bound(begin(a) + j, end(a), a[i] * (p + 1)) - begin(a);
            sum += (k - j) * p;
            j = k;
            p = a[j] / a[i];
        } while (j < n);
        res += sum;
        prevSum = sum;
    }
    cout << res << '\n';
    return 0;
}