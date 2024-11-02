#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int n = size(a), m = size(b);
    int i = 0;
    while (i < min(n, m) and a[i] == b[i]) ++i;
    cout << (i == n ? "Yes" : "No") << '\n';
    return 0;
}