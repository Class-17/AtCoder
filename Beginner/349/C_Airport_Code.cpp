#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    s.push_back('X');
    int len = 0;
    for (auto &ch : s)
        if (len < 3 and toupper(ch) == t[len])
            ++len;
    cout << (len == 3 ? "Yes" : "No") << '\n';
    return 0;
}