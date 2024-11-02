#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 2; i <= n; ++i)
        cin >> arr[i];
    int cnt = 0, idx = n;
    while (idx) {
        idx = arr[idx];
        ++cnt;
    }
    cout << cnt - 1 << '\n';
    return 0;
}