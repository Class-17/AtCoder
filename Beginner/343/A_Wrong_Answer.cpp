#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if (a + b + 1 > 9)
        cout << 0 << '\n';
    else
        cout << a + b + 1 << '\n';
    return 0;
}