#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c;
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto &x : a) c.push_back(x);
    for (auto &x : b) c.push_back(x);
    ranges::sort(c);
    set st(begin(a), end(a));
    for (int i = 0; i + 1 < n + m; ++i) {
        if (st.count(c[i]) and st.count(c[i + 1])) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}