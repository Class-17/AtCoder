#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x <= k) st.insert(x);
    }
    i64 sum = (k + 1LL) * k / 2;
    for (auto &x : st) sum -= x; 
    cout << sum << '\n';
    return 0;
}