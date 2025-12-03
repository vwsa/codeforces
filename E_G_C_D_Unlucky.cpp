#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> s,p;
    for (int i=0;i<n;i++) {
        int x; cin >> x; p.push_back(x);
    }
    
    for (int i=0;i<n;i++) {
        int x; cin >> x; s.push_back(x);
    }
    if (n==1 && s[0] == p[0]) {
        cout << "YES" << endl;
        return;
    }
    if (p[n-1] != s[0]) {
        cout << "NO" << endl; return;
    }

    int g = s[0];

    for (int i=0;i<n-1;i++) {
        if (__gcd(s[i+1], p[i]) != g) {
            cout << "NO" << endl;
            return;
        }
        if (p[i] % p[i+1] != 0) {
            cout << "NO" << endl;
            return;
        }
        if (s[i+1] % s[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}