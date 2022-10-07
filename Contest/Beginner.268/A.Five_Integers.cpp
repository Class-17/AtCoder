#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> arr(5);
    for (auto &x : arr) cin >> x;
    cout << size(set(begin(arr), end(arr))) << '\n';
    return 0;
}