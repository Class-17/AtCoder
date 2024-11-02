#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n), b(n);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    std::vector<int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::ranges::sort(ord, {}, [&](int i) {return a[i];});
    std::priority_queue<int> pq;
    i64 res = 1e18, sum = 0;
    for (auto &i : ord) {
        pq.emplace(b[i]);
        sum += b[i];
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k) {
            res = std::min(res, sum * a[i]);
        }
    }    
    std::cout << res << '\n';
    return 0;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int _; std::cin >> _;
    while (_--) solve();
    return 0;
}