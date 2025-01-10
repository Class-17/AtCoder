#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    char c1, c2;
    std::cin >> c1 >> c2;
    std::string s; std::cin >> s;
    for (auto &c : s)
        if (c != c1) c = c2;
    std::cout << s << '\n';
    return 0;
}