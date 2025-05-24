#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k,p;
    cin >> n >> k >> p;
    if (abs(n * p) > abs(k)) {
        cout << "-1" << endl; return;
    }
    k = abs(k); p = abs(p);
    int x = 0;
    if (k % p != 0) x = 1; 
    cout << k / p + x << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}