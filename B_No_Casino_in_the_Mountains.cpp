#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n+2, 0);
    vector<int> b(n+1,0);
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    int consecutive = 0;
    int ans = 0;
    for (int i=1;i<=n;i++) {
        if (a[i] == 0) {
            consecutive += 1;
        } else {
            consecutive = 0;
        }
        if (consecutive == k) {
            ans++;
            consecutive = 0;
            a[i+1] = 1;
        }
    }
    cout << ans << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}