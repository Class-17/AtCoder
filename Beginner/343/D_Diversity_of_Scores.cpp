#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    vector<i64> arr(n), a(t), b(t);
    for (int i = 0; i < t; ++i)
        cin >> a[i] >> b[i];
    map<i64, int> cnt;
    cnt[0] = n;
    for (int i = 0; i < t; ++i) {
        i64 pre_score = arr[a[i] - 1];
        --cnt[pre_score];
        if (cnt[pre_score] == 0)
            cnt.erase(pre_score);
        arr[a[i] - 1] += b[i];
        ++cnt[pre_score + b[i]];
        cout << size(cnt) << '\n';
    }
    return 0;
}