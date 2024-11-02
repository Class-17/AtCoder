#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    std::ranges::sort(s);
    std::cout << (s == "ABC" ? "Yes" : "No") << '\n';
    return 0;
}