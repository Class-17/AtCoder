#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; ++i)
        s += "10";
    s.push_back('1');
    cout << s << '\n';
    return 0;
}