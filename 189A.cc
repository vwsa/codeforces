#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        if (i >= a && (i == a || dp[i-a] != 0)) {
            dp[i] = max(dp[i], dp[i-a] + 1);
        }
        if (i >= b && (i == b || dp[i-b] != 0)) {
            dp[i] = max(dp[i], dp[i-b] + 1);
        }
        if (i >= c && (i == c || dp[i-c] != 0)) {
            dp[i] = max(dp[i], dp[i-c] + 1);
        }       
    }
    cout << dp[n] << endl;
}