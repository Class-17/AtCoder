#include <bits/stdc++.h>
#include <atcoder/all>

using mint = atcoder::modint1000000007;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<mint> fac(n + 1), inv(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = fac[i - 1] * i;
    for (int i = 0; i <= n; ++i)
        inv[i] = fac[i].inv();
    auto c = [fac, inv](int n, int m) {
        return fac[n] * inv[m] * inv[n - m];
    };
    for (int k = 1; k <= n; ++k) {
        mint res = 0;
        for (int i = 1; i + (i - 1) * (k - 1) <= n; ++i)
            res += c(n - (k - 1) * (i - 1), i);
        std::cout << res.val() << '\n';
    }
    return 0;
}