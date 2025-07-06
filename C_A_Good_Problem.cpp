#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,l,r,k;
    cin >> n >> l >> r >> k;
    
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 1) {
        cout << l << endl;
        return;
    }
    int p = 2;
    int can = -1;
    while (p <= 1e18) {
        if (l < p && p <= r) {
            can = p;
            break;
        }
        p *= 2;
    }
    if (can == -1) {
        cout << can << endl;
        return;
    }
    if (k <= n-2) {
        cout << l << endl;
        return;
    } else {
        cout << can << endl;
        return;
    }
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}