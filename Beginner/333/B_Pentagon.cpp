#include <bits/stdc++.h>
using namespace std;

int f(char a, char b) {
    int x = a - 'A', y = b - 'A';
    if ((x - 1 + 5) % 5 == y or (x + 1) % 5 == y)
        return 2;
    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    if (f(s[0], s[1]) == f(t[0], t[1]))
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}