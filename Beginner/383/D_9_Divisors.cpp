#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6;

std::vector<i64> primes;
std::bitset<N + 1> st;
auto init = []() {
    for (int i = 2; i <= N; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= N; j += i)
            st[j] = 1;
        primes.push_back(i);
    }
    return 0;
} ();

i64 f(i64 x) {
    if (x >= 2e3) return LLONG_MAX;
    return x * x * x * x;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; std::cin >> n;
    for (auto &x : primes) x = x * x;
    i64 res = 0;
    for (int i = 0; i < primes.size(); ++i) {
        if (f(primes[i]) <= n) res += 1;
        if (primes[i] > n) break;
        int j = std::upper_bound(primes.begin() + i + 1, primes.end(), n / primes[i]) - primes.begin();
        res += j - i - 1;
    }
    std::cout << res << '\n';
    return 0;
}