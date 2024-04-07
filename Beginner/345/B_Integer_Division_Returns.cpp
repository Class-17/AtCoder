#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long x; cin >> x;
    if (x >= 0)
        cout << (x + 9) / 10 << '\n';
    else
        cout << x / 10 << '\n';
    return 0;
}