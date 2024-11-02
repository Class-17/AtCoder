#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    sort(begin(s), end(s));
    auto check = [&]() {
        for (int i = 0; i < 10; ++i)
            if (s[i] != i + '0') return i;
        return 9;
    };
    cout << check() << '\n';
    return 0;
}