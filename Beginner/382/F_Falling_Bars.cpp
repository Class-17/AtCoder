#include <bits/stdc++.h>
#include <atcoder/all>

int op(int a, int b) {return std::min(a, b);}

int e() {return INT_MAX;}

int mapping(int f, int x) {return std::min(f, x);}

int composition(int f, int g) {return std::min(f, g);}

int id() {return INT_MAX;}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector<int> r(n), c(n), l(n);
    for (int i = 0; i < n; ++i)
        std::cin >> r[i] >> c[i] >> l[i];
    std::vector<int> ord(n), res(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::ranges::sort(ord, {}, [&](int i) {return -r[i];});
    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> sgt(std::vector<int>(w + 1, h + 1));
    for (auto &i : ord) {
        res[i] = sgt.prod(c[i], c[i] + l[i]) - 1;
        sgt.apply(c[i], c[i] + l[i], res[i]);
    }
    for (auto &x : res)
        std::cout << x << '\n';
    return 0;
}