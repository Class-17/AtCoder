#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    set<string> st;
    int n = size(s);
    for (int i = 0; i < n; ++i)
        for (int j = 1; i + j <= n; ++j)
            st.insert(s.substr(i, j));
    cout << size(st) << '\n';
    return 0;
}