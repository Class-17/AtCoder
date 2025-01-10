#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == b and b == c or (std::max({a, b, c}) * 2 == a + b + c))
        std::cout << "Yes" << '\n';
    else
        std::cout << "No" << '\n';
    return 0;
}