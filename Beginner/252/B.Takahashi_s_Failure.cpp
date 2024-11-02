#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    set<int> st(begin(b), end(b));
    int val = *max_element(begin(a), end(a));
    auto check = [&]() {
        for (int i = 0; i < n; ++i)
            if (a[i] == val and st.count(i + 1))
                return true;
        return false;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}