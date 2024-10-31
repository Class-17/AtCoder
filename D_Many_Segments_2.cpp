#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

i64 f(i64 n) {
    return n * (n + 1) / 2;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i)
        std::cin >> l[i] >> r[i];
    std::vector<int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::ranges::sort(ord, [&](const auto &a, const auto &b) {
        return std::pair{l[a], r[b]} < std::pair{l[b], r[b]};
    });
    std::vector<int> itvs;
    for (auto &i : ord) {
        while (!itvs.empty() and r[itvs.back()] >= r[i])
            itvs.pop_back();
        itvs.push_back(i);
    }
    n = itvs.size();
    i64 res = 0;
    int pl = 1, pr = 1;
    for (auto &i : itvs) {
        i64 lo = std::max(0, std::min(pr, l[i]) - pl);
        i64 hi = std::max(0, r[i] - pr - 1);
        res += lo * hi;
        res += f(r[i] - l[i] + 1) - 1;
        if (l[i] < pr) res -= f(pr - l[i] + 1);
        pl = l[i];
        pr = r[i];
    }
    res += f(m - pr);
    std::cout << res << '\n';
    return 0;
}