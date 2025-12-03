#include <bits/stdc++.h>
using namespace std;
int dp[501][501];

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i<=n;i++){
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int len = 1; len <= n; len++) { // 500
        for (int l = 1; l <= n; l++) { // 500
            int r = l + len - 1;
            if (r > n) {
                break;
            }
            if (l == r) {
                dp[l][r] = a[l];
                continue;
            }
            for (int mid = l; mid <= r; mid++) {
                if (mid + 1 > r) {
                    break;
                }
                if (dp[l][mid] <= 10000 && abs(dp[l][mid] - dp[mid+1][r]) == 0) {
                    dp[l][r] = dp[l][mid] + 1;
                }
            }
        }
    }
    int dpp[505];
    memset(dpp, 0x3f, sizeof(dpp));
    dpp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int len = 1; len <= i; len++) {
            if (dp[i - len + 1][i] <= 10000) {
                dpp[i] = min(dpp[i], dpp[i - len] + 1);
            }
        }
    }
    cout << dpp[n] << endl;
    return 0;
}