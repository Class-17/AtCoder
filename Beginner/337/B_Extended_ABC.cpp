#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s), i = 0;
    while (i < n and s[i] == 'A') ++i;
    while (i < n and s[i] == 'B') ++i;
    while (i < n and s[i] == 'C') ++i;
    cout << (i == n ? "Yes" : "No") << '\n';
    return 0;
}