#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    const string s = "atcoder";
    int l, r;
    cin >> l >> r;
    cout << s.substr(l - 1, r - l + 1) << '\n';
    return 0;
}