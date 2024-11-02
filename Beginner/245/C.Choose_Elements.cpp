#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    auto check = [&]() {
        auto test = [&](int pre, int val) {
            if (pre == -1) return false;
            return abs(pre - val) <= k;
        };
        int x = a.front(), y = b.front();
        for (int i = 1; i < n; ++i) {
            int nx = (test(x, a[i]) or test(y, a[i]) ? a[i] : -1);
            int ny = (test(x, b[i]) or test(y, b[i]) ? b[i] : -1);
            tie(x, y) = pair{nx, ny};
        }
        return x != -1 or y != -1;
    };
    cout << (check() ?  "Yes" : "No") << '\n';
    return 0;
}