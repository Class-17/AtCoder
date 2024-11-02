#include <bits/stdc++.h>
using namespace std;

template<class T>
class UnionFind {
private:
    vector<T> dsu;
public:
    UnionFind(int n = 0) : dsu(n, -1) {}

    T find(T x) {
        if (dsu[x] < 0) return x;
        return dsu[x] = find(dsu[x]);
    }

    bool same(T x, T y) {
        return find(x) == find(y);
    }

    bool unite(T x, T y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (dsu[x] > dsu[y]) swap(x, y);
        dsu[x] += dsu[y];
        dsu[y] = x;
        return true;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> de(n + 1);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++de[u];
        ++de[v];
    }
    UnionFind<int> circle(n + 1), list(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (de[i] == 1) q.push(i);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto &v : g[u]) {
            if (--de[v] == 1) q.push(v);
            list.unite(u, v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (de[i] == 1) continue;
        for (auto &j : g[i])
            circle.unite(i, j);
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        int a = circle.same(u, v), b = list.same(u, v);
        if ((!a and b) or (a and b))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}