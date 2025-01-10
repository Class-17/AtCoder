#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    auto count = [a, n](int d) {
        std::vector<int> st(n);
        int res = 1;
        for (int i = 0; i < n; ++i) {
            if (st[i]) continue;
            int cnt = 0;
            for (int j = i; j < n; j += d) {
                if (a[j] != a[i]) break;
                st[j] = 1;
                cnt += 1;
            }
            res = std::max(res, cnt);
        }
        return res;
    };
    int res = 1;
    for (int i = 1; i <= n; ++i)
        res = std::max(res, count(i));
    std::cout << res << '\n';
    return 0;
}