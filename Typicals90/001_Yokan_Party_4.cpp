#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, l, k;
    std::cin >> n >> l >> k;
    std::vector<int> a(n);
    a.push_back(l);
    for (auto &x : a) std::cin >> x;
    auto check = [&](int t) {
        int prev = 0, cnt = 0;
        for (auto &x : a) {
            if (x - prev < t) continue;
            cnt += 1;
            prev = x;
        }
        return cnt >= k + 1;
    };
    int res = 0;
    for (int i = 1 << 30; i > 0; i >>= 1)
        if (check(res + i)) res += i;
    std::cout << res << '\n';
    return 0;
}