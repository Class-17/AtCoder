#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, l;
    cin >> n >> l;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        res += (x >= l);
    }
    cout << res << '\n';
    return 0;
}