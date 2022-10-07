#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 3000;

bitset<maxn> st[maxn];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> g(n);
    for (auto &row : g) cin >> row;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (g[i][j] == '1') st[i][j] = 1;
    ll res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j + 1 < n; ++j)
            if (st[i][j])
                res += (st[i] & st[j]).count();
    cout << res << '\n';
    return 0;
}