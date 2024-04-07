#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> c(n);
    for (auto &x : c) cin >> x;
    i64 sum = accumulate(begin(c), end(c), 0LL), cur = 0;
    for (int i = 0; i < n; ++i)
        if (i % 2 != s[i] - '0') cur += c[i];
    i64 res = sum;
    for (int i = 0; i + 1 < n; ++i) {
        cur += (i % 2 != s[i] - '0') ? -c[i] : c[i];
        res = min({res, cur, sum - cur});
    }
    cout << res << '\n';
    return 0;
}