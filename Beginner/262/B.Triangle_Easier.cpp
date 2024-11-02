#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    bitset<maxn> st[maxn];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        st[u - 1][v - 1] = st[v - 1][u - 1] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (st[i][j] and st[j][k] and st[k][i]) ++cnt;
    cout << cnt << '\n';
    return 0;
}