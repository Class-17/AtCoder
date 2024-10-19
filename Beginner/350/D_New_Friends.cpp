#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<class T>
class UnionFind {
private:
    vector<T> dsu, cnt;
public:
    UnionFind(int n = 0) : dsu(n, -1), cnt(n, 0) {}

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

    T count(T x) {
        return -dsu[find(x)];
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    UnionFind<int> dsu(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }
    i64 res = 0;
    vector<int> st(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x = dsu.find(i);
        if (st[x]) continue;
        int sz = dsu.count(x);
        res += sz * (sz - 1LL) / 2;
        st[x] = 1;
    }
    cout << res - m << '\n';
    return 0;
}