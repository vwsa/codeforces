#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int MAXN =5001;
int dp[MAXN][MAXN];
bool ispd[MAXN][MAXN];
signed main() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {

    }
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) break;
            if (len == 1) {
                dp[l][r] = 1;
                ispd[l][r] = 1;
            } else {
                ispd[l][r] = (((l+1 > r-1) && s[l] == s[r]) || ((ispd[l+1][r-1]) && (s[l] == s[r])));
                dp[l][r] = dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1] + ispd[l][r];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << dp[l][r] << endl;
    }
}