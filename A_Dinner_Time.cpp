#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m,p,q;
    cin >> n >> m >> p >> q;
    if (n % p == 0) {
        if (n / p * q != m) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    } else {
        cout << "YES" << endl;
    }
}
int main() {
    int T;
    cin >>T;
    while (T--) {
        solve();   
    }
}