#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int f(int x) {
    if (x == 0) return 0;
    int res = 1;
    for (int i = 2; i * i <= x; ++i) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            ++cnt;
        }
        if (cnt & 1) res *= i;
    }
    if (x > 1) res *= x;
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    i64 res = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        x = f(x);
        if (x == 0)
            res += i;
        else
            res += cnt[x] + cnt[0];
        ++cnt[x];
    }
    cout << res << '\n';
    return 0;
}