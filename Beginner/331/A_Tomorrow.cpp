#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int M, D;
    cin >> M >> D;
    int y, m, d;
    cin >> y >> m >> d;
    d = d + 1;
    if (d > D) {
        d = 1;
        m = m + 1;
    }
    if (m > M) {
        m = 1;
        y = y + 1;
    }
    cout << y << ' ' << m << ' ' << d << '\n';
    return 0;
}