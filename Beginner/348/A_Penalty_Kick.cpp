#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
        cout << (i % 3 ? 'o' : 'x');
    return 0;
}