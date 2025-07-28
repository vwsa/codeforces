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
    }
    int ans1 = v[0] + v[1];
    int ans2 = v[0] * 2;
    // int minn = v[0];
    // for (int i=1;i<n;i++) {
    //     if (minn > v[i]) minn = v[i];
    //     ans2 += minn;
    // }
    cout << min(ans1,ans2) << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}