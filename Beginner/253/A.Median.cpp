#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    if (a > c) swap(a, c);
    cout << (a <= b and b <= c ? "Yes" : "No") << '\n';
    return 0;
}