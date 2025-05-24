#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x,y;
    cin >> x >> y;
    if (( x > y && (x-y+1)%9 == 0) || (y == x+1)) cout << "YES" <<endl;
    else cout << "NO" << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}