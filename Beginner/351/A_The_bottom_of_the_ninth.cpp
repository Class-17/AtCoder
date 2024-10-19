#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int res = 0;
    for (int i = 0; i < 9; ++i) {
        int x; cin >> x;
        res -= x;
    }
    for (int i = 0; i < 8; ++i) {
        int x; cin >> x;
        res += x;
    }
    cout << max(0, -res) + 1 << '\n';
    return 0;
}