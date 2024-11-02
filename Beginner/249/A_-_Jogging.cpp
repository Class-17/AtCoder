#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c, d, e, f, t;
    cin >> a >> b >> c >> d >> e >> f >> t;
    auto [x, rx] = div(t, a + c);
    auto [y, ry] = div(t, d + f);
    x = x * a * b + min(a, rx) * b;
    y = y * d * e + min(d, ry) * e;
    if (x > y)
        cout << "Takahashi" << '\n';
    else if (x < y)
        cout << "Aoki" << '\n';
    else
        cout << "Draw" << '\n';
    return 0;
}