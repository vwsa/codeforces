#include <bits/stdc++.h>
#include <limits>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    if (count(a.begin(), a.end(), 1) == a.size()) {
        cout << "YES" << endl;
        return;
    }
    for (int i=1;i<n;i++) {
        if (a[i] == a[i-1] && !a[i]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
int main() {
    int T; cin >> T;
    while (T--) solve();
}