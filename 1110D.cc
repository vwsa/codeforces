#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v(m+1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    int dp[m+1][3][3]; // [i][j][k]: j 个 (i-1, i), k 个 i
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++ ) {
            for (int k = 0; k < 3; k++ ) {
                for (int l = 0; l < 3; l++ ) {
                    if (v[i] < j + k + l) continue;
                    dp[i][j][k] = max(
                        dp[i][j][k], // j  (i-1, i),  k i
                        dp[i-1][l][j] + k + (v[i] - l - j - k) / 3 //  (i-2, i-1)  i-1
                    );
                }
            }
        }
    }
    cout << dp[m][0][0] << endl;
}