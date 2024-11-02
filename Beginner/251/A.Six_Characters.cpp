#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 6;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s);
    string res;
    for (int i = 0; i < lim / n; ++i)
        res += s;
    cout << res << '\n';
    return 0;
}