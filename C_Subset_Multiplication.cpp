#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int x = 1;
    for (int i=n-2;i>=0;--i) {
        if (a[i+1]%a[i] != 0) {
            a[i] = a[i] / x;
            int newly_added = a[i] / __gcd(a[i], a[i+1]);
            x *= newly_added;
            a[i] /= newly_added;
        }
    }
    cout << x << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}