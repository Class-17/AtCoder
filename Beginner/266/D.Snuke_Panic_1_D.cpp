#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxt = 1e5 + 1, maxx = 5;

constexpr ll inf = LLONG_MAX;

int arr[maxt][maxx];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int lim = 0;
    for (int i = 0; i < n; ++i) {
        int t, x, a;
        cin >> t >> x >> a;
        arr[t][x] = a;
        lim = t;
    }
    vector<ll> dp(maxx, -inf);
    auto get = [&](int idx) {
        if (idx < 0 or idx >= maxx) return -inf;
        return dp[idx];
    };
    dp[0] = 0;
    for (int i = 1; i <= lim; ++i) {
        vector<ll> curr(maxx, -inf);
        for (int j = 0; j < maxx; ++j)
            curr[j] = max({get(j - 1), get(j), get(j + 1)}) + arr[i][j];
        dp = move(curr);
    }
    cout << max(*max_element(begin(dp), end(dp)), 0LL) << '\n';
    return 0;
}