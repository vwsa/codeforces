#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &x: v) {
        cin >> x;
    }
    int st = v[0];
    int ed = v[n-1];
    int ans1 = abs(ed-s) + (ed-st);
    int ans2 = abs(s-st) + (ed - st);
    cout << min(ans1, ans2) << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}