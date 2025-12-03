#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int a,b,c,d;
    for (int i=0;i<n;i++) {
        cin >> a >> b >> c >> d;
        ans += abs(a-c) + abs(b-d);
        if (b > d) {
            ans += min(a,c) * 2;
        }
    }
    ans /= 2;
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}