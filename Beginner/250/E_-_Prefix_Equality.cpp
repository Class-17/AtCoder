#include <bits/stdc++.h>
using namespace std;

vector<int> count(vector<int>& arr) {
    int n = size(arr);
    set<int> st;
    vector<int> len(n);
    for (int i = 0; i < n; ++i) {
        st.insert(arr[i]);
        len[i] = size(st);
    }
    return len;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    auto len_a = count(a), len_b = count(b);
    set<int> st;
    vector<int> is_same(n);
    for (int i = 0, j = 0; i < n; ++i) {
        while (i < n and len_a[i + 1] == len_a[i]) ++i;
        while (j < n and len_b[j + 1] == len_b[j]) ++j;
        if (st.count(a[i])) st.erase(a[i]);
        else                st.insert(a[i]);
        if (st.count(b[j])) st.erase(b[j]);
        else                st.insert(b[j]);
        if (st.empty()) is_same[i] = 1;
    }
    auto check = [&](int x, int y)->bool {
        if (len_a[x] != len_b[y]) return false;
        x = upper_bound(begin(len_a), end(len_a), len_a[x]) - begin(len_a) - 1;
        return is_same[x];
    };
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        cout << (check(x - 1, y - 1) ? "Yes" : "No") << '\n';
    }
    return 0;
}