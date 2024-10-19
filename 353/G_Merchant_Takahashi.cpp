#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 INF = 1e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, c;
    cin >> n >> c;
    int m; cin >> m;
    vector<i64> dp(n + 1, -INF), st(n + 1);
    dp[1] = 0;
    st[1] = 1;
    for (int i = 0; i < m; ++i) {
        i64 t, p;
        cin >> t >> p;
        if (st[t]) dp[t] += p;
        st[t] = 1;
        for (int j = 1; j <= n; ++j)
            if (st[j] and j != t)
                dp[t] = max(dp[t], dp[j] + p - abs(t - j) * c);
     }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}