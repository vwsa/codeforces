#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int a,b,k;
    cin >> a >> b >> k;
    if (max(a / __gcd(a,b), b / __gcd(a,b)) <= k) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}