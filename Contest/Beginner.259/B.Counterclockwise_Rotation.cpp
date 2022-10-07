#include <bits/stdc++.h>
using namespace std;

constexpr double PI = 2 * acos(0.0);;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    double a, b, d;
    cin >> a >> b >> d;
    d = d * PI / 180.0;
    double x = a * cos(d) - b * sin(d);
    double y = a * sin(d) + b * cos(d);
    cout << fixed << setprecision(12) << x << ' ' << y << '\n';
    return 0;
}