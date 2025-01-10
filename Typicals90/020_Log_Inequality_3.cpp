#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 a, b, c;
    std::cin >> a >> b >> c;
    i64 e = 1;
    for (int i = 0; i < b; ++i)
        e *= c;
    std::cout << (a < e ? "Yes" : "No") << '\n';
    return 0;
}