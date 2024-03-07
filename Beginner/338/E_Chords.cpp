#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (auto &[a, b] : arr) {
        cin >> a >> b;
        if (a > b) swap(a, b);
    }
    sort(begin(arr), end(arr));
    set<int> st;
    for (auto &[a, b] : arr) {
        auto p = st.lower_bound(a);
        if (p != end(st) and *p < b) {
            cout << "Yes" << '\n';
            return 0;
        }
        st.insert(b);
    }
    cout << "No" << '\n';
    return 0;
}