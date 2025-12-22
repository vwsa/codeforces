#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,k;
    cin >> n >> k;
    if (k == 1 || (k % 2) == 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " ";
        }
        cout << endl;
        return;
    }
    int x = 0, y = 0;
    int step = -1;
    for (int i = 30; i >= 0; i--) {
        int check = (1 << i);
        if ((check & n) != 0) {
            if (step == -1) {
                x |= check;
                // y same
                step = 0;
                continue;
            } else if (step == 0) {
                // x same as x < n
                y |= check;
                step = 1;
                continue;
            } else if (step == 1) {
                y |= check;
                continue;
            }
        } else {
            if (step == -1) {
                continue;
            } else if (step == 0) {
                continue;
            } else if (step == 1) {
                x |= check;
                y |= check;
                continue;
            }
        }
    }
    for (int i = 0; i < k - 2; i++) {
        cout << n << " ";
    }
    cout << x << " " << y << endl;
    return;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}