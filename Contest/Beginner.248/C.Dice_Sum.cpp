#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dp(k + 1);
    dp[0] = 1;
    while (n--) {
        vector<int> curr(k + 1);
        for (int i = 0; i <= k; ++i)
            for (int j = 1; i + j <= k and j <= m; ++j)
                curr[i + j] = (curr[i + j] + dp[i]) % mod;
        dp = move(curr);
    }
    int res = 0;
    for (auto &x : dp)
        res = (res + x) % mod;
    cout << res << '\n';
    return 0;
}