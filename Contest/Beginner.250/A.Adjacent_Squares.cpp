#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    int cnt = 0;
    cnt += (r != 1) + (r != h);
    cnt += (c != 1) + (c != w);
    cout << cnt << '\n';
    return 0;
}