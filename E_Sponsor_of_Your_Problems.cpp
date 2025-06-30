#include <bits/stdc++.h>
#include <string>
using namespace std;
void solve() {
    int a,b;
    cin >> a >> b;
    // string x = std::to_string(a);
    // int n = x.size();
    // int c = b - a;
    // if (c == 0) {
    //     cout << 2*n << endl;
    // } else if (1 == c) {
    //     cout << 2*n-1 << endl;
    // } else if (2 <= c && c <= 10) {
    //     cout << 2*n-2 << endl;
    // } else if (11 <= c && c <= 11) {
    //     cout << 2*n-3 << endl; 
    // }else if (2 <= c && c <= 10) {
    //     cout << 2*n-2 << endl;
    // }
    string x,y;
    x = std::to_string(a);
    y = std::to_string(b);
    int ans = 0;
    int did = 0;
    for (int i=0;i<x.size();i++) {
        if (x[i] == y[i]) {
            ans += 2;
            continue;
        }
        if (abs(x[i] - y[i]) == 1) {
            ans += 1;
            int ii = i+1;
            while (ii < x.size() &&  x[ii] == '9' && y[ii] == '0') {
                ans += 1;
                ii++;
            }
            break;
        }
        break;
    }
    cout << ans << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}