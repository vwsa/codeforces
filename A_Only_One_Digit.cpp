#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int minn = 10;
    while (n) {
         minn = min(minn, n%10);
        n/=10;  
    }
    cout << minn << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}