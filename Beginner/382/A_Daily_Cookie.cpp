#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    std::cin >> n >> d;
    std::string s; std::cin >> s;
    std::cout << std::count(s.begin(), s.end(), '.') + d << '\n';
    return 0;
}