/*
- dp[i][j] = 
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXX = 1061109567;

int dp[MAXN][MAXN];
int dpp[MAXN];
int n;
int a[MAXN];
int main() {
    memset(dp, 0x3f, sizeof(dp));
    memset(dpp,0x3f,sizeof(dpp));
    memset(a,0,sizeof(a));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) break;
            if (i == j) {
                dp[i][j] = a[i]; continue;
            }
            for (int k = i; k < j; k++) {
                if (dp[i][k] < MAXX && std::abs(dp[i][k] - dp[k+1][j]) == 0) {
                    dp[i][j] = dp[k+1][j] + 1;
                }
            }
        }
    }
    dpp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            if (dp[j][i] < MAXX) {
                dpp[i] = min(dpp[i], dpp[j-1] + 1);
            }
        }
    }
    cout << dpp[n] << endl;
}
