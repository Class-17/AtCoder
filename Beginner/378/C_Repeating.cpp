#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::map<int, int> idx;
    for (int i = 1; i <= n; ++i) {
        int x; std::cin >> x;
        std::cout << (idx.contains(x) ? idx[x] : -1) << " \n"[i == n];
        idx[x] = i;
    }
    return 0;
}