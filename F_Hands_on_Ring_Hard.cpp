#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<char> h(q);
    std::vector<int> t(q);
    for (int i = 0; i < q; ++i)
        std::cin >> h[i] >> t[i];
    return 0;
}