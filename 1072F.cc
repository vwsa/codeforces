#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x,y;
    cin >> x >> y;
    x += y;
    if (x % 3 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}