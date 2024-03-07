#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20;

constexpr int INF = 0x3f3f3f3f;

int f[1 << N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int g[N][N];
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u][v] = w;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1 ^ 1) continue;
            for (int k = 0; k < n; ++k) {
                if ((i ^ 1 << j) >> k & 1) {
                    int back = min(0, g[j][k]);
                    f[i][j] = min(f[i][j], f[i^1<<j][k] + g[k][j] + back);
                }
            }
        }
    }
    int res = INF;
    for (int i = 0; i < n; ++i)
        res = min(res, f[(1 << n) - 1][i]);
    if (res >= INF)
        cout << "No" << '\n';
    else
        cout << res;
    return 0;
}