#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    int a[100001], dp[100001]; 
    memset(a, 0, sizeof(a)); memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i < 100001; i++) {
        if (i == 1 || i == 2) {
            dp[i] = a[i] * i;
            continue;
        }
        dp[i] = max(dp[i-2], dp[i-3]) + (a[i] * i);
    }
    cout << max(dp[100000], dp[99999]) << endl;
}