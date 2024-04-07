#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; cin >> n;
    string s, t;
    cin >> s >> t;
    int sl = size(s), tl = size(t);
    vector<int> pos[26];
    for (int i = 0; i < sl * 2; ++i)
        pos[s[i % sl] - 'a'].push_back(i);
    cout << *ranges::partition_point(views::iota(1LL, n*(i64)size(s)+1), [&](i64 k) {
        i64 iter = 0;
        for (auto &ch : t) {
            const auto &p = pos[ch - 'a'];
            if (p.empty()) return false;
            auto [d, r] = div(k - 1, size(p) / 2);
            auto it = ranges::lower_bound(p, iter % sl);
            iter += d * sl + (*(it + r) - iter % sl) + 1;
            if (iter > n * sl) return false;
        }
        return true;
     }) - 1 << '\n';
    return 0;
}