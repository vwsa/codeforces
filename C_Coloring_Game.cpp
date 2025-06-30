#include <algorithm>
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
    sort(a.begin(), a.end());
    int maxx = a[n-1];
    int ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            int lb = lower_bound(a.begin() + j + 1, a.end(), maxx - (a[i]+a[j]) + 1) - a.begin();
            int rb = lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]) - a.begin();
            int len = rb - lb - 2;
            if (len <= 0) {
                continue;
            } else {
                ans += len;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}
