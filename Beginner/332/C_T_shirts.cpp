#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    int tot = 0, tL = 0, tP = m;
    for (auto &ch : s) {
        if (ch == '0') {
            tL = tot;
            tP = m;
        }
        else if (ch == '1') {
            if (tP == 0) {
                --tL;
            }
            else {
                --tP;
            }
        }
        else {
            --tL;
        }
        if (tL < 0) {
            ++tL;
            ++tot;
        }
    }
    cout << tot << '\n';
    return 0;
}