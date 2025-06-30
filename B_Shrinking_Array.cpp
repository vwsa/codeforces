#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    int ans = LONG_LONG_MAX;

    for (int i=1;i<n;i++) {
        int j = i - 1;
        if (abs(a[i] - a[j]) <= 1) {
            cout << "0" << endl;
            return;
        }
        if (a[j] < a[i]) {
            --j;
            while (j >= 0) {
                if (a[j] >= a[i]) {
                    ans = min(ans, i - j - 1);
                    break;
                }
                --j;
            }
        } else {
            while (j >= 0) {
                if (a[j] <= a[i]) {
                    ans = min(ans, i - j - 1);
                    break;
                }
                --j;
            }
        }
    }

    reverse(a.begin(), a.end());
    for (int i=1;i<n;i++) {
        int j = i - 1;
        if (abs(a[i] - a[j]) <= 1) {
            cout << "0" << endl;
            return;
        }
        if (a[j] < a[i]) {
            --j;
            while (j >= 0) {
                if (a[j] >= a[i]) {
                    ans = min(ans, i - j - 1);
                    break;
                }
                --j;
            }
        } else {
            while (j >= 0) {
                if (a[j] <= a[i]) {
                    ans = min(ans, i - j - 1);
                    break;
                }
                --j;
            }
        }
    }
    if (ans == LONG_LONG_MAX) {
        ans = -1;
    }
    cout << ans << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}
