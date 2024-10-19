#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), idx(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        idx[p[i]] = i;
    }
    set<int> st;
    int res = n;
    for (int i = 1, j = 1; j <= n; ++i) {
        while (j <= n and j - i + 1 <= k) {
            st.insert(idx[j]);
            j++;
        }
        if (j - i == k and !st.empty())
            res = min(res, *rbegin(st) - *begin(st));
        st.erase(idx[i]);
    }
    cout << res << '\n';
    return 0;
}