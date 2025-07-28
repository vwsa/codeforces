#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a,b,k;
    cin >> a >> b >> k;
    if (max(a / __gcd(a,b), b / __gcd(a,b)) <= k) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}