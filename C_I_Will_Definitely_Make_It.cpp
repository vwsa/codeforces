#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int now = a[k-1];
    int first = now;
    sort(a.begin(), a.end());
    while (1) {
        int next_id = upper_bound(a.begin(), a.end(), now) - a.begin();
        if (next_id >= n) {
            break;
        }
        int next = a[next_id];
        if (next - now > first) {
            cout << "NO" << endl;
            return;
        }
        now = next;
    }
    cout << "YES" << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}