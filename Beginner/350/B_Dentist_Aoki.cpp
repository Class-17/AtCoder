#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> st(n, 1);
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        st[x - 1] ^= 1;
    }
    cout << count(begin(st), end(st), 1) << '\n';
    return 0;
}