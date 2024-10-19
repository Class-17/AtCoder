#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int res = 0;
    for (int i = 0; i < n - 2; ++i)
        if (s.substr(i, 3) == "#.#")
            res += 1;
    std::cout << res << '\n';
    return 0;
}