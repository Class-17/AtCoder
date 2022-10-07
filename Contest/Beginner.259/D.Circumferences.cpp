#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<tuple<ll, ll, ll>> circles(n);
    for (auto &[x, y, r] : circles)
        cin >> x >> y >> r;
    vector<vector<int>> g(n);
    auto check = [&](int i, int j) {
        auto [x1, y1, r1] = circles[i];
        auto [x2, y2, r2] = circles[j];
        ll x = x1 - x2, y = y1 - y2;
        ll d = x * x + y * y;
        if (d == 0) return false;
        if (d == ll(r1) * r1) return r1 * 2 >= r2;
        if (d == ll(r2) * r2) return r2 * 2 >= r1;
        ll lo = r1 - r2, hi = r1 + r2;
        return lo * lo <= d and d <= hi * hi;
    };
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (check(i, j)) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
    auto in_circle = [&](int idx, ll px, ll py) {
        auto [x, y, r] = circles[idx];
        ll dx = x - px, dy = y - py;
        ll dr = r * r;
        return dx * dx + dy * dy == dr;
    };
    auto bfs = [&]() {
        queue<int> q;
        vector<int> st(n);
        for (int i = 0; i < n; ++i) {
            if (!in_circle(i, sx, sy)) continue;
            q.push(i);
            st[i] = 1;
        }
        while (!q.empty()) {
            auto idx = q.front(); q.pop();
            if (in_circle(idx, tx, ty)) return true;
            for (auto &ver : g[idx]) {
                if (st[ver]) continue;
                q.push(ver);
                st[ver] = 1;
            }       
        }
        return false;
    };
    cout << (bfs() ? "Yes" : "No") << '\n';
    return 0;
}