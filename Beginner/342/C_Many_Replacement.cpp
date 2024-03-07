#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    map<char, string> mp;
    for (char c = 'a'; c <= 'z'; ++c)
        mp[c].push_back(c);
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        char a, b;
        cin >> a >> b;
        if (a == b) continue;
        mp[b] += mp[a];
        mp[a] = "";
    }
    map<char, char> res;
    for (auto &[c, s] : mp) {
        for (auto &ch : s)
            res[ch] = c;
    }
    for (auto &c : s)
        if (mp.contains(c)) c = res[c];
    cout << s << '\n';
    return 0;
}