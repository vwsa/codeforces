#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c;
    vector<int> v(2);
    cin >> a;
    cin >> v[0] >> v[1];
    sort(v.begin(), v.end());

    if (a < v[0] || a > v[1]) {
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