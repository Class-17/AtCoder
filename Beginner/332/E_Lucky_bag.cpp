#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> w(n);
    for (auto &x : w) cin >> x;
    int m = n - 1;
    double res = 1e9, ax = accumulate(begin(w), end(w), 0.0) / d;
    sort(begin(w), end(w));
    // do {
        for (int i = 0; i < (1 << m); ++i) {
            vector<int> bags;
            int curr = w[0];
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    bags.push_back(curr);
                    curr = 0;
                }
                curr += w[j + 1];
            }
            bags.push_back(curr);
            if (size(bags) > d) continue;
            double sum = 0.0;
            for (auto &x : bags)
                sum += (x - ax) * (x - ax);
            for (int j = size(bags); j < d; ++j)
                sum += ax * ax;
            res = min(res, sum / d);
        }
    // } while (next_permutation(begin(w), end(w)));
    cout << setprecision(16) << fixed << res << '\n';
    return 0;
}