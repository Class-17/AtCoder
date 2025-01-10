#include <bits/stdc++.h>
#include <atcoder/all>

using i64 = long long;

using S = i64;
S op(S a, S b) {return std::max(a, b);}
S e() {return -1;}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int w, n;
    std::cin >> w >> n;
    atcoder::segtree<S, op, e> dp(w + 1);
    dp.set(0, 0);
    for (int i = 0; i < n; ++i) {
        int l, r, v;
        std::cin >> l >> r >> v;
        for (int k = w; k >= l; --k) {
            int lo = l, hi = std::min(r, k);
            i64 up = dp.prod(k - hi, k - lo + 1);
            if (up >= 0 and up + v > dp.get(k)) dp.set(k, up + v);
        }
    }
    std::cout << dp.get(w) << '\n';
    return 0;
}