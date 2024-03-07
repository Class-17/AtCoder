#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 v = lcm(n, m);
    cout << *ranges::partition_point(views::iota(0LL, n*k*3LL), [&](auto x) {
        return x / n  + x / m - x / v * 2 < k;}) << '\n';
    return 0;
}