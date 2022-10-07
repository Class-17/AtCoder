#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 2e5;

ll sum[maxn + 1];

int lowbit(int x) {return x & -x;}

void add(int idx, ll x) {
    for (; idx <= maxn; idx += lowbit(idx))
        sum[idx] += x;
}

ll ask(int idx) {
    ll res = 0;
    for (; idx > 0; idx -= lowbit(idx))
        res += sum[idx];
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> t(q + 1), a(q + 1), b(q + 1), c(q + 1);
    vector<vector<int>> seq(q + 1);
    vector<int> latest(n + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> t[i];
        if (t[i] == 1) {
            cin >> a[i] >> b[i] >> c[i];
        }
        else if (t[i] == 2) {
            cin >> a[i] >> b[i];
            latest[a[i]] = i;
        }
        else if (t[i] == 3) {
            cin >> a[i] >> b[i];
            seq[latest[a[i]]].push_back(i);
        }
    }
    for (int i = 1; i <= q; ++i) {
        if (t[i] == 1) {
            add(a[i], c[i]);
            add(b[i] + 1, -c[i]);
        }
        else if (t[i] == 2) {
            for (auto &j : seq[i])
                c[j] = b[i] - ask(b[j]);
        }
        else if (t[i] == 3) {
            cout << c[i] + ask(b[i]) << '\n';
        }
    }
    return 0;
}