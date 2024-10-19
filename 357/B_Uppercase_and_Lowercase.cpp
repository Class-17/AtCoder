#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int lo = 0, up = 0;
    for (auto &c : s)
        if (islower(c)) lo += 1;
        else            up += 1;
    if (up > lo)
        for (auto &c : s)
            c = toupper(c);
    else
        for (auto &c : s)
            c = tolower(c);
    cout << s << '\n';
    return 0;
}