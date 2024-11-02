#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using pll = pair<ll, ll>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> w(n);
    for (auto &x : w) cin >> x;
    vector<vector<int>> g(n);
    vector<ll> sum(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        sum[u] += w[v];
        sum[v] += w[u];
    }
    vector<int> st(n);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < n; ++i)
        pq.emplace(sum[i], i);
    ll res = 0;
    while (!pq.empty()) {
        auto [val, idx] = pq.top(); pq.pop();
        if (st[idx]) continue;
        st[idx] = 1;
        res = max(res, val);
        for (auto &v : g[idx]) {
            if (st[v]) continue;
            sum[v] -= w[idx];
            pq.emplace(sum[v], v);
        }
    }
    cout << res << '\n';
    return 0;
}