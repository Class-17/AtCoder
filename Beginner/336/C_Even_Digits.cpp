#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; cin >> n;
    string s;
    n -= 1;
    while (n > 0) {
        s.push_back(n % 5 * 2 + '0');
        n /= 5;
    }
    reverse(begin(s), end(s));
    if (s.empty()) s = "0";
    cout << s << '\n';
    return 0;
}