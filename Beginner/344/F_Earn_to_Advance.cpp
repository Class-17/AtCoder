#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 80;

constexpr pair<i64, i64> INF = {LLONG_MAX, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int p[N][N], r[N][N], d[N][N];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> p[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - 1; ++j)
            cin >> r[i][j];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n; ++j)
            cin >> d[i][j];

    i64 dist[N][N][N][N];
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            dist[i][j][i][j] = 0;
            for (int a = i; a < n; ++a)
                for (int b = j; b < n; ++b) {
                    if (a + 1 < n)
                        dist[i][j][a+1][b] = min(dist[i][j][a+1][b], dist[i][j][a][b] + d[a][b]);
                    if (b + 1 < n)
                        dist[i][j][a][b+1] = min(dist[i][j][a][b+1], dist[i][j][a][b] + r[a][b]);
                }
        }
    pair<i64, i64> dp[N][N];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
          dp[i][j] = INF;
    dp[0][0] = {0, 0};

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            for (int a = i; a < n; ++a)
                for (int b = j; b < n; ++b) {
                    auto [cnt, pre_v] = dp[i][j];
                    pre_v = -pre_v;
                    i64 add = (dist[i][j][a][b] - pre_v + p[i][j] - 1) / p[i][j];
                    add = max(add, 0LL);
                    i64 v = p[i][j] * add + pre_v - dist[i][j][a][b];
                    dp[a][b] = min(dp[a][b], {cnt + add, -v});
                }
        }
    cout << dp[n - 1][n - 1].first + (n - 1) * 2 << '\n';
    return 0;
}