#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2000;
constexpr int V = 1000;

bitset<N> st[N][V];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector mat(n, vector(m, 0));
    for (auto &row : mat)
        for (auto &x : row)
            cin >> x;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        bitset<N> cur;
        for (int j = 0; j < m; ++j) {
            cur ^= st[j][mat[i][j]];
            st[j][mat[i][j]].set(i);
        }
        res += cur.count();
    }
    cout << res << '\n';
    return 0;
}