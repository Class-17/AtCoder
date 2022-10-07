#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<string, int> mp;
    mp["Monday"] = 1;
    mp["Tuesday"] = 2;
    mp["Wednesday"] = 3;
    mp["Thursday"] = 4;
    mp["Friday"] = 5;
    string s; cin >> s;
    cout << 6 - mp[s] << '\n';
    return 0;
}