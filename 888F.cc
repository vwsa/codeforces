#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e2 + 10;
int e[MAXN][MAXN];
int f[MAXN][MAXN][2];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> e[i][j];
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            for (int k = i; k <= j; k++) {
                f[i][j][0] += f[i][k][0] * f[k][j][0] * 
            }
        }
    }


}