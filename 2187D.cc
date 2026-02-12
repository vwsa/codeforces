#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int x,y;
    cin >> x >> y;
    int p,q;
    int ans = LONG_LONG_MAX;
    p = x;
    q = y;
    for (int i = 30; i >= 0; --i) {
        if ((((1 << i) & x) & ((1 << i) & y)) == 0) {
            continue;
        } else {
            int p1 = (((x >> i) + 1) << i); 
            int q1 = y;
            if ((p1 & q1) == 0 && abs(p1 - x) + abs(q1 - y) < ans) {
                p = p1;
                q = q1;
                ans = abs(p1 - x) + abs(q1 - y);
            }
            int p2 = (((x >> i) << i) - 1);
            int q2 = ((y >> i) << i);
            if ((p2 && q2) == 0 && abs(x - p2) + abs(y - q2) < ans) {
                p = p2;
                q = q2;
                ans = abs(x - p2) + abs(y - q2);
            }
            int p3 = x;
            int q3 = ((y >> i) + 1) << i;
            if ((p3 & q3) == 0 && abs(x - p3) + abs(y - q3) < ans) {
                p = p3;
                q = q3;
                ans = abs(x - p3) + abs(y - q3);
            }
            int p4 = ((x >> i) << i);
            int q4 = ((y >> i) << i) - 1;
            if ((p4 & q4) == 0 && abs(x - p4) + abs(y - q4) < ans) {
                p = p4;
                q = q4;
                ans = abs(x - p4) + abs(y - q4);
            }
            break;
        }
    }
    cout << p << " " << q << endl;

}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}