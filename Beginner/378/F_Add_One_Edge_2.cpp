#include <bits/stdc++.h>
#include <atcoder/dsu>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> es(n - 1);
    std::vector<int> de(n + 1);
    for (auto &[u, v] : es) {
        std::cin >> u >> v;
        de[u] += 1;
        de[v] += 1;
    }
    atcoder::dsu d(n + 1);
    std::vector<int> cnt(n + 1);
    for (auto &[u, v] : es) {
        if (de[u] == 3 and de[v] == 3)
            d.merge(u, v);
        else if (de[u] == 2 and de[v] == 3)
            cnt[v] += 1;
        else if (de[u] == 3 and de[v] == 2)
            cnt[u] += 1;
    }
    i64 res = 0;
    for (auto &part : d.groups()) {
        i64 sum = 0;
        for (auto &i : part)
            sum += cnt[i];
        res += sum * (sum - 1) / 2;
    }
    std::cout << res << '\n';
    return 0;
}