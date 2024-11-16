#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = (i + 1) * (s[i] - '0');
    std::partial_sum(a.begin(), a.end(), a.begin());
    std::string res;
    i64 sum = 0;
    for (auto &x : a | std::views::reverse) {
        sum += x;
        res.push_back(sum % 10 + '0');
        sum /= 10;
    }
    if (sum > 0) res += std::to_string(sum);
    std::reverse(res.begin(), res.end());
    std::cout << res << '\n';
    return 0;
}