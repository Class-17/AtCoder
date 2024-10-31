#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    int l = 0, r = 1, res = 0;

    auto test = [&](int x, int y, int t, int d) {
        int cnt = 0;
        while (x != t) {
            x = (x + d + n) % n;
            if (x == y) return n;
            cnt += 1;
        }
        return cnt;
    };
    for (int i = 0; i < q; ++i) {
        std::string h;
        int t;
        std::cin >> h >> t; --t;
        if (h == "L") {
            res += std::min(test(l, r, t, +1), test(l, r, t, -1));
            l = t;
        }
        else {
            res += std::min(test(r, l, t, +1), test(r, l, t, -1));
            r = t;
        }
    }
    std::cout << res << '\n';
    return 0;
}