#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;


i64 f(i64 a0, i64 n) {
    return (a0 * 2 - n + 1) * n / 2;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> x(m), a(m), ord(m);
    for (auto &v : x) std::cin >> v;
    for (auto &v : a) std::cin >> v;
    std::iota(ord.begin(), ord.end(), 0);
    std::ranges::sort(ord, {}, [&](int i) {return x[i];});
    if (x[ord.back()] < n) {
        ord.push_back(m);
        x.push_back(n);
        a.push_back(0);
    }
    i64 res = 0, sum = 0, prev = 0;
    for (auto &i : ord) {
        if (sum < x[i] - 1 - prev) {
            std::cout << -1 << '\n';
            return 0;
        }
        i64 d = x[i] - 1 - prev;
        res += f(sum, x[i] - prev);
        sum = sum - d + a[i];
        if (sum < 1) {
            std::cout << -1 << '\n';
            return 0;
        }
        sum -= 1;
        prev = x[i];
    }
    std::cout << (sum > 0 ? -1 : res) << '\n';
    return 0;
}