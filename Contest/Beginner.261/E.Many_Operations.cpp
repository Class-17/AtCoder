#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    int mask = (1 << 30) - 1;
    int zero = 0, one = mask;
    for (int i = 0; i < n; ++i) {
        int t, a;
        cin >> t >> a;
        if (t == 1)
            one &= a, zero &= a;
        else if (t == 2)
            one |= a, zero |= a;
        else
            one ^= a, zero ^= a;
        c = (c & one) | ((c ^ mask) & zero);
        cout << c << '\n';
    }
    return 0;
}