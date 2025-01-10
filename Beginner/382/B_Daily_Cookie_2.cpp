#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    std::cin >> n >> d;
    std::string s; std::cin >> s;
    for (int i = n - 1; i >= 0 and d > 0; --i)
        if (s[i] == '@') {
            s[i] = '.';
            d -= 1;
        }
    std::cout << s << '\n';
    return 0;
}