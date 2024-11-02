#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, bool, int>> arr(n + m);
    for (int i = 0; i < n; ++i)
        cin >> get<0>(arr[i]);
    for (int i = 0; i < n; ++i)
        cin >> get<2>(arr[i]);
    for (int i = n; i < n + m; ++i)
        cin >> get<0>(arr[i]);
    for (int i = n; i < n + m; ++i)
        cin >> get<2>(arr[i]);
    for (int i = 0; i < n + m; ++i)
        get<1>(arr[i]) = (i >= n);
    sort(rbegin(arr), rend(arr));
    auto check = [&]() {
        multiset<int> st;
        for (auto &[w, t, l] : arr) {
            if (t) st.insert(l);
            else {
                auto obj = st.lower_bound(l);
                if (obj == end(st)) return false;
                st.erase(obj);
            }
        }
        return true;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}