#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int m = s.size();
    s = "#" + s;
    int n; cin >> n;
    vector<int> dp(m + 1, n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        auto f = dp;
        for (int j = 0; j < a; ++j) {
            string t; cin >> t;
            int len = size(t);
            for (int k = m; k >= len; --k)
                if (s.substr(k - len + 1, len) == t)
                    dp[k] = min(dp[k], f[k - len] + 1);
        }
    }
    cout << (dp[m] <= n ? dp[m] : -1) << '\n';
    return 0;
}