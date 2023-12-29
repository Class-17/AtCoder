#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 f(i64 a, i64 b) {
    i64 r = (a % b + b) % b;
    return (a - r) / b;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	i64 a, m, l, r;
    cin >> a >> m >> l >> r;
    cout << f(r - a, m) - f(l - a - 1, m) << '\n';
	return 0;
}