#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    set<i64> st;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        x = (x - 1) % (a + b) + 1;
        st.insert(x);
    }
    st.insert(*begin(st) + (a + b));
    i64 prev = *begin(st), res = 0;
    for (auto &x : st) {
        res = max(res, x - prev);
        prev = x;
    }
    cout << (res > b ? "Yes" : "No") << '\n';
    return 0;
}