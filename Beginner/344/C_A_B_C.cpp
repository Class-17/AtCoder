#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    set<int> st{0};
    for (int i = 0; i < 3; ++i) {
        int len; cin >> len;
        set<int> cur;
        for (int j = 0; j < len; ++j) {
            int x; cin >> x;
            for (auto &y : st)
                cur.insert(x + y);
        }
        st = move(cur);
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << (st.count(x) ? "Yes" : "No") << '\n';
    }
    return 0;
}