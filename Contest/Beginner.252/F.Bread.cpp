#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, l; cin >> n >> l;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    priority_queue<ll, vector<ll>, greater<>> pq(begin(arr), end(arr));
    ll sum = accumulate(begin(arr), end(arr), 0LL);
    if (l > sum) pq.push(l - sum);
    ll cost = 0;
    while (size(pq) > 1) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    cout << cost << '\n';
    return 0;
}