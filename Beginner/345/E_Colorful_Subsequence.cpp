#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

using pairI64 = pair<i64, i64>;

constexpr i64 INF = 1e15;

void insert(vector<pairI64> &a, const pairI64 &x) {
    const auto &[v, c] = x;
    if (a[0].second == c) {
        a[0].first = max(a[0].first, v);
        return;
    }
    if (a[1].second == c) {
        a[1].first = max(a[1].first, v);
        return;
    }
    if (a[1].first < v) a[1] = x;
    if (a[0].first < v) swap(a[0], a[1]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> c[i] >> v[i];
    vector dp(2, vector(k + 1, vector(2, pairI64{-INF, 0})));
    dp[0][0][0].first = dp[0][0][1].first = 0;
    for (int i = 1; i <= n; ++i) {
        auto &cur = dp[i & 1], &pre = dp[~i & 1];
        for (int j = k; j >= 0; --j) {
            cur[j][0].first = cur[j][1].first = -INF;
            cur[j][0].second = cur[j][1].second = 0;
        }
        for (int j = k; j >= 0; --j)
            for (auto &[val, color] : pre[j])
                if (c[i] != color)
                    insert(cur[j], {val + v[i], c[i]});
        for (int j = k; j > 0; --j)
            for (auto &[val, color] : pre[j - 1])
                insert(cur[j], {val, color});
    }
    i64 res = dp[n & 1][k][0].first;
    cout << (res >= 0 ? res : -1) << '\n';
    return 0;
}