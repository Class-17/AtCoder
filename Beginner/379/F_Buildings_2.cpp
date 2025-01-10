#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::vector<std::pair<int, int>> queries(q);
    for (auto &[l, r] : queries)
        std::cin >> l >> r, --l, --r;
    std::vector<int> ord(q), res(q);
    std::iota(ord.begin(), ord.end(), 0);
    std::ranges::sort(ord, [&](const auto &x, const auto &y) {
        return queries[x].second > queries[y].second;
    });
    std::vector<int> stk;
    atcoder::segtree<int, [](int x, int y) {return std::max(x, y);}, []() {return 0;}> sgt(a);
    int p = n - 1;
    for (auto &i : ord) {
        const auto &[l, r] = queries[i];
        while (p > r) {
            while (!stk.empty() and stk.back() < a[p])
                stk.pop_back();
            stk.push_back(a[p--]);
        }
        int lo = 0, hi = stk.size();
        int t = sgt.prod(l + 1, r + 1);
        while (lo < hi) {
            int mid = lo + hi >> 1;
            if (stk[mid] >= t)
                lo = mid + 1;
            else
                hi = mid;
        }
        res[i] = lo;
    }
    for (auto &x : res)
        std::cout << x << '\n';
    return 0;
}