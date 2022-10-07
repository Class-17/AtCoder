#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    const string s = "FMT";
    int v, a, b, c;
    cin >> v >> a >> b >> c;
    v %= a + b + c;
    if (v < a) cout << "F\n";
    else if (v < a + b) cout << "M\n";
    else                cout << "T\n";
    return 0;
}