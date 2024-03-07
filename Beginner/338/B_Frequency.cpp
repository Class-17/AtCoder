#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    map<char, int> cnt;
    for (auto &c : s)
        ++cnt[c];
    int maxc = 0;
    for (auto &[k, v] : cnt)
        maxc = max(maxc, v);
    for (auto &[k, v] : cnt)
        if (v == maxc) {
            cout << k << '\n';
            break;
        }
    return 0;
}