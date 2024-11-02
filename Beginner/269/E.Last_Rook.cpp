#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int c, int d, int tag) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    int x; cin >> x;
    assert(x != -1);
    if (tag == 0) return x < b;
    return x < d;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int a = 1, b = n;
    while (a < b) {
        int mid = a + b >> 1;
        if (check(1, mid, 1, n, 0)) b = mid;
        else                        a = mid + 1;
    }
    int c = 1, d = n;
    while (c < d) {
        int mid = c + d >> 1;
        if (check(1, n, 1, mid, 1)) d = mid;
        else                        c = mid + 1;
    }
    cout << "! " << a << ' ' << c << endl;
    return 0;
}