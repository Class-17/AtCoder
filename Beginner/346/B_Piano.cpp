#include <bits/stdc++.h>
using namespace std;

const string S = "wbwbwwbwbwbw";
const int N = size(S);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int w, b;
    cin >> w >> b;
    for (int i = 0; i < N; ++i) {
        int cw = 0, cb = 0;
        for (int j = 0; j < w + b; ++j)
            if (S[(i + j) % N] == 'w') ++cw;
            else                       ++cb;
        if (cw == w and cb == b) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}