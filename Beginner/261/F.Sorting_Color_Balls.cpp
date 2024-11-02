#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
class FenwickTree {
private:
    int n;
    vector<T> sum;
    int lowbit(int x) {return x & -x;}
public:
    FenwickTree(int n = 0) : n(n), sum(n + 1) {}
 
    void add(int x, T d) {
        for (; x <= n; x += lowbit(x))
            sum[x] += d;
    }

    T ask(int x) {
        T res = 0;
        for (; x; x -= lowbit(x))
            res += sum[x];
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> color(n + 1);
    vector<pair<int, int>> arr(n);
    for (auto &[c, x] : arr) cin >> c;
    for (auto &[c, x] : arr) cin >> x;
    for (int i = 0; i < n; ++i) {
        auto [c, x] = arr[i];
        color[c].emplace_back(i);
    }
    ll cnt = 0;
    FenwickTree<int> t(n);
    for (auto &seq : color) {
        for (auto &idx : seq) {
            auto &[c, x] = arr[idx];
            cnt -= t.ask(n) - t.ask(x);
            t.add(x, 1);
        }
        for (auto &idx : seq) {
            auto &[c, x] = arr[idx];
            t.add(x, -1);
        }
    }
    for (auto &[c, x] : arr) {
        cnt += t.ask(n) - t.ask(x);
        t.add(x, 1);
    }
    cout << cnt << '\n';
    return 0;
}