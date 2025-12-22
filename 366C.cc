#include <bits/stdc++.h>
using namespace std;
const int TMAX = 1e5+5, DELTA = 1e5 + 1;
int f[TMAX * 2], g[TMAX * 2], a[TMAX], b[TMAX];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = a[i] - k*b[i];
    }
    g[0+DELTA] = 0;
    f[0+DELTA] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = DELTA - 100000; j <= DELTA + 100000; j++) {
            if (j - b[i] >= 0 && j - b[i] <= 10000+ DELTA && g[j-b[i]] != -1) {
                f[j] = max(g[j], g[j-b[i]] + a[i]);
            }
            memcpy(g, f, sizeof(f));
        }
    }
    printf("%d", f[0+DELTA] == 0? -1 : f[0 + DELTA]);
    return 0;
}