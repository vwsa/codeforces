#include <bits/stdc++.h>
using namespace std;
const int MAXN = 702;
int a[MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN];
int g[MAXN][MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (__gcd(a[i], a[j]) > 1) {
                g[i][j] = 1;
            }
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            if (r > n) {break;}
            for (int k = l; k <= r; k++) {
                if ((l <= k-1?L[l][k-1]:1) && (r >= k+1?R[k+1][r]:1)) {
                    if (g[l-1][k]) R[l][r] = 1;
                    if (g[k][r+1]) L[l][r] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if ((1 <= i-1?L[1][i-1]:1) && (n >= i+1?R[i+1][n]:1)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}