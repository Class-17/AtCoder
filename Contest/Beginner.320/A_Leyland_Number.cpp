#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
    if (b == 0) return 1;
    return f(a, b - 1) * a;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << f(a, b) + f(b, a) << '\n';
    return 0;
}