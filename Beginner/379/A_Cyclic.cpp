#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s; std::cin >> s;
    std::cout << s[1] << s[2] << s[0] << ' ';
    std::cout << s[2] << s[0] << s[1] << '\n';
    return 0;
}