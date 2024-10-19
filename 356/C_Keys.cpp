#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> tests(m);
    for (auto &test : tests) {
        int c; cin >> c;
        test.resize(c + 2);
        test[0] = c;
        for (int i = 1; i <= c; ++i)
            cin >> test[i];
        string r; cin >> r;
        test[c + 1] = (r == "o");
    }
    auto check = [&](int mask) {
        vector<int> st(n + 1);
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1) st[i + 1] = 1;
        for (auto &test : tests) {
            int cnt = 0;
            for (int i = 1; i <= test[0]; ++i)
                cnt += st[test[i]];
            if ((cnt >= k) != test.back()) return false;
        }
        return true;
    };
    int res = 0;
    for (int i = 0; i < (1 << n); ++i)
        if (check(i)) res += 1;
    cout << res << '\n';
    return 0;
}