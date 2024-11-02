#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, q, m;
    cin >> n >> q >> m;
    vector<int> w(n);
    for (auto &x : w) cin >> x;
    ll sum = accumulate(begin(w), end(w), 0LL);
    ll base = m / sum * n;
    m %= sum;
    vector<int> cnt(n);
    for (ll i = 0, j = 0, curr = 0; i < n; ++i) {
        while (curr < m) curr += w[j++ % n];
        cnt[i] = j - i;
        curr -= w[i];
    }
    vector<ll> seq, st(n, -1);
    int p = 0, tag = 0;
    while (true) {
        if (st[p] != -1) {
            tag = st[p];
            break;
        }
        st[p] = size(seq);
        seq.push_back(cnt[p] + base);
        p = (p + cnt[p]) % n;
    }
    ll gap = size(seq) - tag;
    for (int i = 0; i < q; ++i) {
        ll k; cin >> k;
        --k;
        if (k <= tag)
            cout << seq[k] << '\n';
        else
            cout << seq[(k - tag) % gap + tag] << '\n';
    }
    return 0;
}