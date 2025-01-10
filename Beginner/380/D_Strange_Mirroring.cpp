#include <bits/stdc++.h>

using i64 = long long;

char flip(char ch, int bit) {
    if (bit == 0) return ch;
    if (islower(ch)) return toupper(ch);
    return tolower(ch);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s; std::cin >> s;
    int q; std::cin >> q;
    while (q--) {
        i64 k; std::cin >> k;
        auto [d, r] = std::div(k - 1, s.size());
        std::cout << flip(s[r], __builtin_popcountll(d) & 1) << " ";
    }
    return 0;
}