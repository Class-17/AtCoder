#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k, g, m;
    cin >> k >> g >> m;
    int a = 0, b = 0;
    for (int i = 0; i < k; ++i) {
        if (a == g) {
            a = 0;
        }
        else if (b == 0) {
            b = m;
        }
        else {
            while (b > 0 and a < g) {
                --b;
                ++a;
            }
        }
    }
    cout << a << ' ' << b << '\n';
    return 0;
}