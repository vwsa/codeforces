#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
void solve() {
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    if (s[0] == '0' || s[n-1] == '0' || c == 1) {
        cout << "-1" << endl;
        return;
    }
    int res = 1;
    int res2 = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (s[i - 1] == '0') {
            res *= (i-1);
            res %= MOD;
            res2 *= (i-1);
            res2 %= c;
        } else {
            res *= 2;
            res %= MOD;
            res2 *= 2;
            res2 %= c;
        }
    }
    if (res2 == 0) {
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}