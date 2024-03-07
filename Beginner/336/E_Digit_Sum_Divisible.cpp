#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int LIM = 1e7;

bitset<LIM + 1> st;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    i64 n; cin >> n;
    // for (int i = 1; i <= 9; ++i)
    //     st[i] = 1;
    for (i64 i = 1; i * i <= n; ++i) {
        if (st[i]) continue;
        for (i64 j = i; j * j <= n; j += i)
            st[j] = 1;
    }
    return 0;
}