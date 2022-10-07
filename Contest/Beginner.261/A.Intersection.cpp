#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int res = min(r1, r2) - max(l1, l2);
    cout << (res > 0 ? res : 0) << '\n';
    return 0;
}