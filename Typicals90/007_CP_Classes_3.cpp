#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::ranges::sort(a);
    int q; std::cin >> q;
    while (q--) {
        int x; std::cin >> x;
        auto p = std::lower_bound(a.begin(), a.end(), x);
        int res = 1e9;
        if (p != a.end())
            res = std::min(res, *p - x);
        if (p != a.begin())
            res = std::min(res, x - *(p - 1));
        std::cout << res << '\n';
    }
    return 0;
}