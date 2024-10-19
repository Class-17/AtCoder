#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s), cnt[26]{};
    for (auto &ch : s)
        ++cnt[ch - 'a'];
    for (int i = 1; i <= n; ++i) {
        int tot = 0;
        for (int j = 0; j < 26; ++j)
            tot += (cnt[j] == i);
        if (tot != 0 and tot != 2) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n"; 
    return 0;
}