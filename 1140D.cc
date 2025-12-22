#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int MAXN = 5e2 + 10;
int dp[MAXN][MAXN];
signed main() {
    cin >> n;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len;
            if (j > n) break;
            dp[i][j] = LONG_LONG_MAX;
            for (int k = i+1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + i * j * k);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}