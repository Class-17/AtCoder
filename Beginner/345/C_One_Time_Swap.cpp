#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int cnt[26]{};
    for (auto &ch : s)
        ++cnt[ch - 'a'];
    i64 res = 0;
    for (auto &ch : s)
        for (int i = ch - 'a' + 1; i < 26; ++i)
            res += cnt[i];
    int multi = 0;
    for (int i = 0; i < 26; ++i)
        if (cnt[i] > 1) multi = 1;
    cout << res + multi << '\n';
    return 0;
}