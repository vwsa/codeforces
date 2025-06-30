#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int x = 0, y = n - 1;
    int ans = 0;
    while (a[x] % 2 != 1) {
        x++;
        ans++;
    }
    while (a[y] % 2 != 1) {
        y--;
        ans++;
    }
    int ans2 = 0;
    x=0,y=n-1;
    while (a[x] % 2 != 0) {
        ans2++;x++;
    }
    while (a[y]%2!=0) {
        y--;ans2++;
    }

    
    cout << min(ans, ans2) << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}