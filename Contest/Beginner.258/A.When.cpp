#include <bits/stdc++.h>
using namespace std;

constexpr int S = 21 * 60;

string f(int x) {
    string h = to_string(x / 60);
    string m = to_string(x % 60);
    while (size(h) < 2) h.insert(begin(h), '0');
    while (size(m) < 2) m.insert(begin(m), '0');
    return h + ":" + m;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k; cin >> k;
    cout << f(S + k) << '\n';
    return 0;
}