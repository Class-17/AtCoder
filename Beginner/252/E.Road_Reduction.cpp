#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

constexpr ll inf = 1e16;

struct edge {
    ll v, w, id;
    edge(ll v, ll w, ll id) : v(v), w(w), id(id) {}
    bool operator < (const edge &e) const {
        return w > e.w;
    }
};

vector<ll> dijkstra(vector<vector<edge>> &g) {
    int n = size(g);
    vector<ll> dist(n, inf), roads(n);
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (dist[u] < d) continue;
        for (auto &[v, w, id] : g[u]) {
            if (dist[v] <= d + w) continue;
            dist[v] = d + w;
            q.emplace(dist[v], v);
            roads[v] = id;
        }
    }
    return roads;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w, i);
        g[v].emplace_back(u, w, i); 
    }
    auto roads = dijkstra(g);
    for (int i = 1; i < n; ++i)
        cout << roads[i] + 1 << (i + 1 < n ? ' ' : '\n');
    return 0;
}