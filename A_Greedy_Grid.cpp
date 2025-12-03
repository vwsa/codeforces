#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    if (n > m) swap(n,m);
    if (n >= 2 && m >= 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}