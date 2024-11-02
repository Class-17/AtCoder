#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int t, x;
        cin >> t >> x;
        if (t == 1)
            cnt = (cnt + x) % n;
        else
            cout << s[(x - cnt - 1 + n) % n] << '\n';
    }
    return 0;
}