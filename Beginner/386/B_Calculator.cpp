#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    int n = s.size(), res = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != '0') continue;
        int j = i + 1;
        while (j < n and s[j] == '0') ++j;
        res -= (j - i) / 2;
        i = j - 1;
    }
    std::cout << res << '\n';
    return 0;
}