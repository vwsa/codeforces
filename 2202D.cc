#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 2) {
        if (k == 2) {
            cout << "YES" << endl;
            cout << "1 1 2 2\n";return;
        } else if (k == 3) {
            cout << "YES" << endl;
            cout << "1 2 2 1\n";return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if (n == 3) {
        if (k == 3) {
            cout << "YES" << endl;
            cout << "1 1 2 2 3 3\n";return;
        } else if (k == 4) {
            cout << "YES" << endl;
            cout << "1 2 2 1 3 3\n";return;
        } else if (k == 5) {
            cout << "YES" << endl;
            cout << "2 1 3 1 2 3\n";return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if (k < n || k > 2 * n - 1) {
        cout << "NO" << endl;
        return;
    }
    if (k == n) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " " << i << " ";
        }
        cout << endl; return;
    }
    cout << "YES\n";
    if (k == n + 1) {
        cout << "1 2 2 1 ";
        for (int i = 3; i <= n; i++) {
            cout << i << " " << i << " ";
        }
        cout << endl;return;
    }
    cout << "2 1 3 1 ";
    for (int i = 4; i <= k - n + 1; i++) {
        cout << i << " " << i - 2 << " ";
    }
    cout << k - n << " " << k - n + 1 << " ";
    for (int i = k - n + 2; i <= n; i++) {
        cout << i << " " << i << " ";
    }
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}