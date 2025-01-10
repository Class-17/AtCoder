#include <bits/stdc++.h>

constexpr int N = 1e4;

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 n, a, b, c;
    std::cin >> n >> a >> b >> c;
    int res = N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; i + j < N; ++j) {
            i64 r = n - (i * a + j * b);
            if (r >= 0 and r % c == 0)
                res = std::min(res * 1LL, i + j + r / c);
        }
    std::cout << res << '\n';
    return 0;
}