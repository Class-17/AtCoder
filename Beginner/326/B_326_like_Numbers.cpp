#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x; cin >> x;
    while (true) {
        int a = x / 100;
        int b = x / 10 % 10;
        int c = x % 10;
        if (a * b == c) {
            cout << x << '\n';
            break;
        }
        ++x;
    }
    return 0;
}