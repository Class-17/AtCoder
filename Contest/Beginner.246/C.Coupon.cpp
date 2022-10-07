#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, x;
    cin >> n >> k >> x;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        pq.push(val);
    }
    while (k && !pq.empty()) {
        auto val = pq.top(); pq.pop();
        int minus = max(min(k, val / x), 1);
        val -= minus * x;
        if (val > 0) pq.push(val);
        k -= minus;
    }
    long long cnt = 0;
    while (!pq.empty()) {
        cnt += pq.top(); pq.pop();
    }
    cout << cnt << '\n';
    return 0;
}