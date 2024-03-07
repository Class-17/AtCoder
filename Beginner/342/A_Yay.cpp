#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    map<char, int> mp;
    for (auto &c : s) ++mp[c];
    for (int i = 0; i < s.size(); ++i) {
        if (mp[s[i]] == 1) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    return 0;
}