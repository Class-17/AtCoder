#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    bool a = isupper(s[0]);
    bool b = true;
    for (int i = 1; i < s.size(); ++i)
        if (isupper(s[i])) b = false;
    cout << (a and b ? "Yes" : "No") << '\n';
    return 0;
}