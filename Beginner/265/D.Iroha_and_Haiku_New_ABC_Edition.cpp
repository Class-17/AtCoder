#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    auto check = [&]() {
        partial_sum(begin(arr), end(arr), begin(arr));
        set st(begin(arr), end(arr));
        st.insert(0);
        for (auto &x : st) {
            if (st.find(x + p) == st.end()) continue;
            if (st.find(x + p + q) == st.end()) continue;
            if (st.find(x + p + q + r) == st.end()) continue;
            return true;
        }
        return false;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}