#include <bits/stdc++.h>

constexpr int N = 5;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int a[N]{};
    for (int i = 0; i < N; ++i)
        std::cin >> a[i];
    std::vector<std::string> names;
    for (int i = 0; i < (1 << N); ++i) {
        std::string s;
        for (int j = 0; j < N; ++j)
            if (i >> j & 1) s.push_back(j + 'A');
        names.push_back(s);
    }
    auto f = [&](const auto &s) {
        int res = 0;
        for (auto &c : s)
            res += a[c - 'A'];
        return res;
    };
    std::ranges::sort(names, {}, [&](const std::string &s) {
        return std::pair{-f(s), s};
    });
    for (auto &name : names)
        std::cout << name << '\n';
    return 0;
}