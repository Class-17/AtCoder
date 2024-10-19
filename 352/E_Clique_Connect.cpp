#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> op1(m);
    vector<vector<int>> op2(m);
    for (int i = 0; i < m; ++i) {
        auto &[k, c] = op1[i];
        cin >> k >> c;
        op2[i].resize(k);
        for (auto &x : op2[i]) cin >> x;
    }
    vector<int> ord(m);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](const auto &a, const auto &b) {
        return op1[a].second < op1[b].second;
    });
    UnionFind<int> dsu(n + 1);
    i64 res = 0, cnt = 0;
    for (auto &i : ord) {
        auto &[k, c] = op1[i];
        auto u = op2[i][0];
        for (auto &v : op2[i]) {
            if (!dsu.same(u, v)) {
                dsu.unite(u, v);
                res += c;
                cnt += 1;
            }
        }
    }
    if (cnt < n - 1) res = -1;
    cout << res << '\n';
    return 0;
}