#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> arr[3];
    for (int i = 0; i < 3; ++i) {
        int len; cin >> len;
        arr[i] = vector<int>(len);
        for (auto &x : arr[i]) cin >> x;
    }
    set<int> st;
    for (int i = 0; i < arr[0].size(); ++i)
        for (int j = 0; j < arr[1].size(); ++j)
            for (int k = 0; k < arr[2].size(); ++k)
                st.insert(arr[0][i] + arr[1][j] + arr[2][k]);
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << (st.count(x) ? "Yes" : "No") << '\n';
    }
    return 0;
}