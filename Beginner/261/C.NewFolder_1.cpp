#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int x = mp[s]++;
        if (x == 0)
            cout << s << '\n';
        else
            cout << s + '(' + to_string(x) + ')' << '\n';
    }
    return 0;
}