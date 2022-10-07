#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a * 60 + b, y = c * 60 + d;
    cout << (x <= y ? "Takahashi" : "Aoki") << '\n';
    return 0;
}