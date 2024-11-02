#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    double x, y;
    cin >> x >> y;
    double z = sqrt(x * x + y * y);
    cout << fixed << setprecision(12) << x / z << ' ' << y / z << '\n';
    return 0;
}