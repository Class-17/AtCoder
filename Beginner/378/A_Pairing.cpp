#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::map<int, int> cnt;
    for (int i = 0; i < 4; ++i) {
        int x; std::cin >> x;
        cnt[x] += 1;
    }
    int res = 0;
    for (auto &[k, v] : cnt)
        res += v / 2;
    std::cout << res << '\n';
    return 0;
}