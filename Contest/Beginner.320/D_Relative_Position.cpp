#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 2e5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> g[N + 1];
    for (int i = 0; i < m; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        --a, --b;
        g[a].emplace_back(b, x, y);
        g[b].emplace_back(a, -x, -y);
    }
    vector<int> st(n);
    st[0] = 1;
    vector<pair<i64, i64>> res(n);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        auto &[sx, sy] = res[u];
        for (auto &[v, x, y] : g[u]) {
            if (st[v]) continue;
            res[v] = pair{sx + x, sy + y};
            st[v] = 1;
            q.push(v);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (st[i])
            cout << res[i].first << ' ' << res[i].second << '\n';
        else
            cout << "undecidable" << '\n';
    }
    return 0;
}