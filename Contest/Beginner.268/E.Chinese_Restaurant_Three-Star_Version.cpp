#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> p(n), pos(n);
    for (auto &x : p) cin >> x;
    for (int i = 0; i < n; ++i)
        pos[p[i]] = i;
    vector<ll> sk(n + 1), sb(n + 1);
    auto add = [&](int l, int r, int k, int b) {
        if (l > r) return;
        sk[l] += k, sk[r + 1] -= k;
        sb[l] += b, sb[r + 1] -= b;
    };
    for (int i = 0; i < n; ++i) {
        int k = (pos[i] - i + n) % n;
        if (k < n / 2) {
            add(0, k - 1, -1, k);
            add(k, k + n / 2, 1, -k);
            add(k + n / 2 + 1, n - 1, -1, n + k);
        }
        else {
            add(0, k - n / 2 - 1, 1, n - k);
            add(k - n / 2, k - 1, -1, k);
            add(k, n - 1, 1, -k);
        }
    }
    partial_sum(begin(sk), end(sk), begin(sk));
    partial_sum(begin(sb), end(sb), begin(sb));
    ll res = LLONG_MAX;
    for (int i = 0; i < n; ++i)
        res = min(res, sk[i] * i + sb[i]);
    cout << res << '\n';
    return 0;
}