#include <bits/stdc++.h>
using namespace std;
int dp[101][101][11][11];
const int MOD = 1e8;
int main() {
    int N1,N2,K1,K2;
    cin >> N1 >> N2 >> K1 >> K2;
    dp[1][0][1][0] = 1;
    dp[0][1][0][1] = 1;
    for (int n1 = 1; n1 <= N1; n1++) {
        for (int n2 = 1; n2 <= N2; n2++) {
            for (int k1 = 1; k1 <= K1; k1++) {
                dp[n1][n2][k1][0] += dp[n1-1][n2][k1 - 1][0];
                dp[n1][n2][k1][0] = dp[n1][n2][k1][0] % MOD;
                dp[n1][n2][0][1] += dp[n1][n2 - 1][k1][0];
                dp[n1][n2][0][1] %= MOD;
            }
            for (int k2 = 1; k2 <= K2; k2++) {
                dp[n1][n2][1][0] += dp[n1-1][n2][0][k2];
                dp[n1][n2][1][0] %= MOD;
                dp[n1][n2][0][k2] += dp[n1][n2 - 1][0][k2 - 1];
                dp[n1][n2][0][k2] %= MOD;
            }
        }
    }
    int res = 0;
    for (int k1 = 1; k1 <= K1; k1++) {
        res += dp[N1][N2][k1][0];
        res %= MOD;
    }
    for (int k2 = 1; k2 <= K2; k2++) {
        res += dp[N1][N2][0][k2];
        res %= MOD;
    }
    cout << res << endl;
    
}