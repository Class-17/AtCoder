#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    vector<ll> bonus(n + 1);
    for (int i = 0; i < m; ++i) {
        ll c, y;
        cin >> c >> y;
        bonus[c] = y;
    }
    vector<ll> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        auto curr = dp;
        for (int j = 0; j <= n; ++j) {
            if (dp[j] == -1) continue;
            if (j + 1 <= n)
                curr[j + 1] = max(curr[j + 1], dp[j] + arr[i] + bonus[j + 1]);
            curr[0] = max(curr[0], dp[j]);
        }
        dp = move(curr);
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}