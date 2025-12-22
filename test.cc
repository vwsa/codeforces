#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
int a[N];
int b[N];
int n,k;
int maxx = 0;

bool check() {
    int xx = 0;
    for (int i = 0; i < k; i++) {
        xx ^= a[i];
    }
    return (xx == n);
}

void dfs(int depth) {
    if (depth == k) {
        if (check()) {
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += a[i];
            }
            if (sum > maxx) {
                maxx = sum;
                for (int i = 0; i < k; i++) b[i] = a[i];
            }
        }
        return;
    }
    for (int i = 0; i <= n; i++) {
        a[depth] = i;
        dfs(depth+1);
    }
}
void solve() {
    cin >> n >> k;
    maxx = 0;
    for (int i = 0; i < N; i++) {
        a[i] = b[i] = 0;
    }
    dfs(0);
    for (int i = 0; i < k; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}