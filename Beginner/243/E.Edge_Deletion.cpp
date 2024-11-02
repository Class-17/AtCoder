#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll inf = 1e15;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> es;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        es.push_back({a - 1, b - 1, c});
    }
    vector<vector<ll>> d(n, vector<ll>(n, inf));
    for (auto &[a, b, c] : es)
        d[a][b] = d[b][a] = c;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int cnt = 0;
    for (auto &[a, b, c] : es) {
        auto check = [&]() {
            for (int i = 0; i < n; ++i)
                if (d[a][i] + d[i][b] <= c) return true;
            return false;
        };
        cnt += check();
    }
    cout << cnt << '\n';
    return 0;
}