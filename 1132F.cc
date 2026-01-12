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
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] - 'a' + 1;
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) break;
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i+1][j] + 1;
            if (i + 1 == j) {
                if (a[i] == a[j]) {
                    dp[i][j] = 1;
                    continue;
                }
            }
            if (a[i] == a[j]) {
            for (int k = i + 2; k <= j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    // dpp[0] = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i; j >= 1; j--) {
    //         if (dp[j][i] < MAXX) {
    //             dpp[i] = min(dpp[i], dpp[j-1] + 1);
    //         }
    //     }
    // }
    // cout << dpp[n] << endl;
}
