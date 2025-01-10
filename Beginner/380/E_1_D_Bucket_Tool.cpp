#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> cnt(n + 2, 1), color(n + 2);
    std::set<int> blocks;
    for (int i = 0; i <= n + 1; ++i) {
        blocks.insert(i);
        color[i] = i;
    }
    while (q--) {
        int t; std::cin >> t;
        if (t == 1) {
            int x, c;
            std::cin >> x >> c;
            auto hi = blocks.upper_bound(x);
            auto lo = std::prev(hi);
            cnt[color[*lo]] -= *hi - *lo;
            color[*lo] = c;
            cnt[color[*lo]] += *hi - *lo;
            if (c == color[*hi])
                blocks.erase(hi);
            if (c == color[*std::prev(lo)])
                blocks.erase(lo);
        }
        else {
            int c; std::cin >> c;
            std::cout << cnt[c] << '\n';
        }
    }
    return 0;
}