#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1), c(n + m + 1);
    for (auto &x : a) cin >> x;
    for (auto &x : c) cin >> x;
    for (int i = m; i >= 0;  --i) {
        b[i] = c[i + n] / a[n];
        for (int j = 0; j <= n; ++j)
            c[i + j] -= a[j] * b[i];
    }
    for (int i = 0; i <= m; ++i)
        cout << b[i] << (i < m ? ' ' : '\n');
    return 0;
}