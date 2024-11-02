#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    map<string, pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        if (!st.count(s))
            st[s] = {x, i};
    }
    int idx = n, val = -1;
    for (auto &[_, x] : st) {
        if (x.first == -1) continue;
        if (idx == n or x.first > val or x.first == val and x.second < idx)
            tie(val, idx) = x;
    }
    cout << idx + 1 << '\n';
    return 0;
}