#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int pos = -1;
    int win = 0;
    vector<int> v(n,0);
    for (int i=0;i<n;i++) {
        cin >> v[i];
        if (i != 0 && win == 0 && v[i] < v[i-1]) {
            win = 1;
            pos = i;
        }
    }
    if (win == 1) {
        cout << "YES" << endl;
        cout << "2" << endl;
        cout << v[pos-1] << " " << v[pos] << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}