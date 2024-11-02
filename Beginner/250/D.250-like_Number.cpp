#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 1e6;

vector<int> primes;

auto sieve = []() {
    bitset<maxn + 1> st;
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i << 1; j <= maxn; j += i)
            st[j] = 1;
        primes.push_back(i);
    }
    return nullptr;
} ();

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n; cin >> n;
    ll cnt = 0;
    for (int i = 0; i < size(primes); ++i) {
        ll q =  1LL * primes[i] * primes[i] * primes[i];
        if (q > n) break;
        cnt += upper_bound(begin(primes), begin(primes) + i, n / q) - begin(primes);
    }
    cout << cnt << '\n';
    return 0;
}