#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long a, b, k;
    cin >> a >> b >> k;
    long long cnt = 0;
    while (a < b) {
        a *= k;
        ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}