#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    int res = 0;
    for (int len = 1; len <= n; ++len) {
        vector dp(len + 1,vector<int>(len));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector curr = dp;
            for (int j = 0; j < len; ++j)
                for (int k = 0; k < len; ++k) {
                    curr[j + 1][(k + arr[i]) % len] += dp[j][k];
                    curr[j + 1][(k + arr[i]) % len] %= mod;
                }
            dp = move(curr);
        }
        res = (res + dp[len][0]) % mod;
    }
    cout << res << '\n';
    return 0;
}