#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> arr(n);
    for (auto &s : arr) cin >> s;
    auto count = [&](int d) {
        vector<int> cnt(10);
        for (auto &s : arr)
            ++cnt[s.find(d + '0')];
        int t = 0;
        for (int i = 0; i < 10; ++i)
            t = max(t, (cnt[i] - 1) * 10 + i);
        return t;
    };
    int time = n * 11;
    for (int i = 0; i < 10; ++i)
        time = min(time, count(i));
    cout << time << '\n';
    return 0;
}