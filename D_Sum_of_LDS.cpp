#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,c;
    cin >> n;
    deque<int> a;
    for (int  i=0;i<n;i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> dp(n+1,0);
    vector<int> count(n+1,0);
    dp[0] = 1; dp[1] = 1;
    count[0] = 1; count[1] = 1;
    if (a[0] > a[1]) {dp[1] = 3; count[1] = 2;}
    for (int i=2;i<n;i++) {
        if (dp[i] < dp[i-1]) {
            count[i] = count[i-1] + 1;
            dp[i] = dp[i-1] + count[i-1] + 1;
        } else {
            count[i] = count[i-2] + 1;
            dp[i] = dp[i-2] + count[i-2] + 1;
        }
    } 
    int ans = 0;
    for (int i=0; i<n;i++) {
        ans += dp[i];
    }
    cout << ans << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}