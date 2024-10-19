#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> names;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int c; cin >> c;
        names.push_back(s);
        tot += c;
    }
    ranges::sort(names);
    cout << names[tot % n] << '\n';
    return 0;
}