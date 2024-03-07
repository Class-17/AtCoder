#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

using info = tuple<int, int, int, int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<info>> g(n + 1), rg(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, d, k, c, a, b;
        cin >> l >> d >> k >> c >> a >> b;
        g[a].emplace_back(b, c, l, d, k);
        rg[b].emplace_back(a, c, l, d, k);
    }
    vector<i64> dist(n + 1, -1);
    priority_queue<pair<i64, int>> pq;
    for (auto &[v, c, l, d, k] : rg[n]) {
        i64 t = l + (k - 1LL) * d;
        pq.emplace(t, v);
        dist[v] = t;
    }
    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (dist[u] > du) continue;
        for (auto &[v, c, l, d, k] : rg[u]) {
            i64 t = dist[v];
            if (l + d * (k - 1LL) + c <= du) {
                t = l + d * (k - 1LL);
            }
            else {
                t = du - c - l;
                auto [di, rem] = div(t, d * 1LL);
                t = l + d * di;
            }
            if (t <= dist[v]) continue;
            pq.emplace(t, v);
            dist[v] = t;
        }
    }
    for (int i = 1; i < n; ++i)
        if (dist[i] < 0)
            cout << "Unreachable" << '\n';
        else
            cout << dist[i] << '\n';
    return 0;
}