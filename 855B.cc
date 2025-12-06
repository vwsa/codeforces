#include <bits/stdc++.h>
using namespace std;
#define int long long
    int x[3];
    int a[100005];
    int dp[100005];
signed main() {
    int n;
    cin >> n;
    cin >> x[0] >> x[1] >> x[2];
    dp[0] = LONG_LONG_MIN;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        dp[i] = a[i] * x[0];
        dp[i] = max(dp[i], dp[i-1]);
    }
    for (int num = 1; num < 3; num++) {
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i] + a[i] * x[num];
            dp[i] = max(dp[i], dp[i-1]);
        }
    }
    cout << dp[n] << endl;

}