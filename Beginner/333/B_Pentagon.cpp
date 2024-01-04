#include <bits/stdc++.h>
using namespace std;

bool near(char a, char b) {
    if (a > b) swap(a, b);
    return b - a == 1 or b - a == 4;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    if (near(s[0], s[1]) == near(t[0], t[1]))
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}