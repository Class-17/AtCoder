#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 12;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<i64> seq = {1};
    for (int i = 1; i < N; ++i)
        seq.push_back(seq.back() * 10 + 1);
    vector<i64> res;
    for (auto &x : seq)
        for (auto &y : seq)
            for (auto &z : seq)
                res.push_back(x + y + z);
    sort(begin(res), end(res));
    res.erase(unique(begin(res), end(res)), end(res));
    int n; cin >> n;
    cout << res[n - 1] << '\n';
    return 0;
}