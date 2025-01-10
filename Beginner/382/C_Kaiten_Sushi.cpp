#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    std::vector<int> ord(m);
    std::iota(ord.begin(), ord.end(), 0);
    std::ranges::sort(ord, {}, [&](int i) {return b[i];});
    std::vector<int> res(m, -1);
    for (int i = 0; i < n; ++i) {
        while (!ord.empty() and b[ord.back()] >= a[i]) {
            res[ord.back()] = i + 1;
            ord.pop_back();
        }
    }
    for (auto &x : res)
        std::cout << x << '\n';
    return 0;
}