#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e3;

constexpr int mod = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> p(n), q(n);
    for (auto &x : p) cin >> x;
    for (auto &x : q) cin >> x;
    vector<map<int, int>> dp(d + 1);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<map<int, int>> curr(d + 1);
        int lo = min(p[i], q[i]) - d, hi = max(p[i], q[i]) + d;
        for (int j = lo; j <= hi; ++j) {
            auto [da, db] = pair{abs(j - p[i]), abs(j - q[i])};
            if (da > d or db > d) continue;
            for (int a = 0; a + da <= d; ++a) {
                for (auto &[b, cnt] : dp[a]) {
                    if (b + db > d) break;
                    curr[a + da][b + db] = (curr[a + da][b + db] + cnt) % mod;
                }
            }
        }
        dp = move(curr);
    }
    int res = 0;
    for (int i = 0; i <= d; ++i)
        for (auto &[j, cnt] : dp[i])
            res = (res + cnt) % mod;
    cout << res << '\n';
    return 0;
}