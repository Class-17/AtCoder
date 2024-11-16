#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::string s; std::cin >> s;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') continue;
        int j = i + 1;
        while (j < n and s[j] == 'O') ++j;
        res += (j - i) / k;
        i = j - 1;
    }
    std::cout << res << '\n';
    return 0;
}