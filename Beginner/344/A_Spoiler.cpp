#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int i = s.find('|'), j = s.rfind('|');
    s.erase(begin(s) + i, begin(s) + j + 1);
    cout << s << '\n';
    return 0;
}