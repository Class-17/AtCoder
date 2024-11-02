#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n, x;
    cin >> n >> x;
    string s; cin >> s;
    string num = bitset<64>(x).to_string();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') num.push_back('0');
        else if (s[i] == 'R') num.push_back('1');
        else num.pop_back();
    }
    cout << bitset<128>(num).to_ullong() << '\n';
    return 0;
}