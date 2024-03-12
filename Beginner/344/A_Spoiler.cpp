#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int i = 0, j = s.size();
    while (i < j and s[i] != '|') ++i;
    while (j > i and s[j - 1] != '|') --j;
    s.erase(begin(s) + i, begin(s) + j);
    cout << s << '\n';
    return 0;
}