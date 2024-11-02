#include <bits/stdc++.h>
using namespace std;

template<class T>
class UnionFind {
public:
    vector<T> fa, sz;
    int n, m;
public:
    UnionFind(int n = 0, int m = 0) : fa(n + m), sz(n + m), n(n), m(m) {
        fa = vector<T>(n + m);
        iota(begin(fa), end(fa), 0);
        sz = vector<T>(n + m);
        for (int i = 0; i < n; ++i)
            sz[i] = 1;
    }

    T find(T x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    bool unite(T x, T y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        if (x < n and y >= n) swap(x, y);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }

    int size(T x) {
        return sz[find(x)];
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, e;
    cin >> n >> m >> e;
    vector<pair<int, int>> es(e);
    for (auto &[u, v] : es) {
        cin >> u >> v;
        --u, --v;
    }
    int q; cin >> q;
    vector<int> qs(q);
    for (auto &x : qs) {
        cin >> x;
        --x;
    }
    set<int> st(begin(qs), end(qs));
    UnionFind<int> dsu(n, m);
    for (int i = 0; i < e; ++i)
        if (st.find(i) == st.end())
            dsu.unite(es[i].first, es[i].second);
    vector<int> res(q);
    int cnt = 0;
    for (int i = 0; i < n + m; ++i) {
        int x = dsu.find(i);
        if (x == i and i >= n) cnt += dsu.size(x);
    }
    for (int i = q - 1; i >= 0; --i) {
        res[i] = cnt;
        int u = dsu.find(es[qs[i]].first);
        int v = dsu.find(es[qs[i]].second);
        if (u >= n and v < n)
            cnt += dsu.size(v);
        else if (u < n and v >= n)
            cnt += dsu.size(u);
        dsu.unite(u, v);
    }
    for (auto &x : res)
        cout << x << '\n';
    return 0;
}