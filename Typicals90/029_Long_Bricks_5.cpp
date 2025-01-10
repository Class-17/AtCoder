#include <bits/stdc++.h>
#include <atcoder/all>

using S = int;
S op(S a, S b) {return std::max(a, b);}
S e() {return 0;}
using F = int;
S mapping(F f, S x) {return std::max(f, x);}
F composition(F f, F g) {return std::max(f, g);}
F id() {return 0;}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> sgt(n + 1);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        int res = sgt.prod(l, r + 1);
        std::cout << res + 1 << '\n';
        sgt.apply(l, r + 1, res + 1);
    }
    return 0;
}