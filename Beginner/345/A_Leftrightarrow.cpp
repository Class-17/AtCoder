#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s);
    if (s[0] != '<' or s[n - 1] != '>') {
        cout << "No" << '\n';
        return 0;
    }
    cout << (s.substr(1, n - 2) == string(n - 2, '=') ? "Yes" : "No") << '\n';
    return 0;
}