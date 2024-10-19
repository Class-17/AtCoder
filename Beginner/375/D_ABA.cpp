#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::string s; std::cin >> s;
    std::vector<i64> cnt(26), sum(26);
    i64 res = 0;
    for (int i = 0; i < s.size(); ++i) {
        int x = s[i] - 'A';
        res += (i - 1) * cnt[x] - sum[x];
        cnt[x] += 1;
        sum[x] += i;
    }
    std::cout << res << '\n';
    return 0;
}