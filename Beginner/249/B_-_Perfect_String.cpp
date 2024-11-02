#include <bits/stdc++.h>
using namespace std;

bool check(const string &s) {
    map<int, int> cnt;
    int low = 0, up = 0;
    for (auto &ch : s) {
        low += islower(ch);
        up += isupper(ch);
        ++cnt[ch];
    }
    for (auto &[_, x]: cnt)
        if (x > 1) return false;
    return low > 0 and up > 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    cout << (check(s) ? "Yes" : "No") << '\n';
    return 0;
}