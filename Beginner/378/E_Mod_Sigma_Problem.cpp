#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        a[i] = (a[i] + a[i - 1]) % m;
    i64 res = 0, sum = 0;
    atcoder::fenwick_tree<int> ft(m);
    for (int i = 1; i <= n; ++i) {
        res += a[i] * i - sum + i64(m) * ft.sum(a[i] + 1, m),
        sum += a[i];
        ft.add(a[i], 1);
    }    
    std::cout << res << '\n';
    return 0;
}