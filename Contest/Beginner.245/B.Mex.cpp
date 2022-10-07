#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(begin(arr), end(arr));
    auto find = [&]() {
        int mex = 0;
        for (auto &x : arr) {
            if (x <= mex) mex = x + 1;
            else          return mex;
        }
        return mex;
    };
    cout << find() << '\n';
    return 0;
}