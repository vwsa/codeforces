#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> s(n);
    for (int i=0;i<n;i++) {
        cin >> p[i];
    }
    for (int i=0;i<n;i++) {
        cin >> s[i];
    }
    vector<int> pre(n);
    vector<int> suf(n);
    int gcd = 0;
    int good = 1;
    for (int i=0;i<n;i++) {
        gcd = __gcd(gcd, p[i]);
        pre[]
    }
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}