#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<int> a(n), b(n - 1);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    std::ranges::sort(a, std::greater<>());
    std::ranges::sort(b, std::greater<>());
    int res = 0, cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (j < n - 1 and b[j] >= a[i]) {
            j += 1;
        }
        else {
            res = a[i];
            cnt += 1;
        }
    }
    std::cout << (cnt == 1 ? res : -1) << '\n';
    return 0;
}