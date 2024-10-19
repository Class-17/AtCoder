#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 f2(i64 x) {
    return x / 2 * 2;
}

i64 c2(i64 x) {
    return (x + 1) / 2 * 2;
}

i64 f4(i64 x) {
    return x / 4 * 4;
}

i64 c4(i64 x) {
    return (x + 3) / 4 * 4;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    a += 1e9;
    b += 1e9;
    c += 1e9;
    d += 1e9;
    i64 area[4]{};
    area[0] = (f2(d) - c2(b)) / 2 * 3;
    if (d % 2 == 1) area[0] += 2;
    if (b % 2 == 1) area[0] += 1;

    area[1] = (f2(d) - c2(b)) / 2 * 3;
    if (d % 2 == 1) area[1] += 1;
    if (b % 2 == 1) area[1] += 2;

    area[2] = (f2(d) - c2(b)) / 2 * 1;
    if (b % 2 == 1) area[2] += 1;

    area[3] = (f2(d) - c2(b)) / 2 * 1;
    if (d % 2 == 1) area[3] += 1;

    i64 tot = area[0] + area[1] + area[2] + area[3];
    i64 res = (f4(c) - c4(a)) / 4 * tot;

    while (a % 4 != 0) {
        res += area[a % 4];
        a += 1;
    }
    while (c % 4 != 0) {
        res += area[(c - 1) % 4];
        c -= 1;
    }
    cout << res  << '\n';
    return 0;
}