#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 a, b, c;
    std::cin >> a >> b >> c;
    i64 x = std::gcd(a, std::gcd(b, c));
    std::cout << (a / x + b / x + c / x - 3) << '\n';
    return 0;
}