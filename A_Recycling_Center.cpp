#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,c;
    cin >> n >> c;
    vector<int> a(n);
    for (int  i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int now = 1;
    int coin = 0;
    for (int i=0;i<n;i++) {
        if (a[i] * now > c) {
            coin++;
        } else {
            now *= 2;
        }
    }

    cout << coin << endl;
    
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}