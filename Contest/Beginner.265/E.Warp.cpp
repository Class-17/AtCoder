#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    array<int, 6> dirs;
    for (auto &x : dirs) cin >> x;
    set<pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        st.emplace(x, y);
    }
    map<pair<ll, ll>, int> dp;
    dp[{0, 0}] = 1;
    for (int i = 0; i < n; ++i) {
        map<pair<ll, ll>, int> curr;
        for (auto &[ps, cnt] : dp) {
            auto &[r, c] = ps;
            for (int d = 0; d < 6; d += 2) {
                auto [nr, nc] = pair{r + dirs[d], c + dirs[d + 1]};
                if (st.find({nr, nc}) != st.end()) continue;
                curr[{nr, nc}] = (curr[{nr, nc}] + cnt) % mod;
            }
        }
        dp = move(curr);
    }
    int res = 0;
    for (auto &[ps, cnt] : dp)
        res = (res + cnt) % mod;
    cout << res << '\n';
    return 0;
}