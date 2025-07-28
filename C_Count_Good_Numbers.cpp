#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int l,r;
    cin >> l >> r;
    auto cal = [&](int x) -> int {
        int bad = x/2 + x/3 + x/5 + x/7 
            - x/6 - x/10 - x/14 - x/15 - x/21 - x/35 
            + x/30 + x/42 + x/70 + x/105 
            - x/210;
        int good = x - bad - 1;
        return good;
    };
    int prel = cal(l - 1);
    int prer = cal(r);
    cout << prer - prel << endl;
    return;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}