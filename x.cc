#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define int long long
const int maxn = 1e5 + 100;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    bool true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.insert(a[i]);
    }
    int ans = -1;
    for (auto iter = nums.begin(); iter != nums.end(); iter++) {
        int l = LONG_LONG_MAX, r = LONG_LONG_MAX;
        if (iter != nums.begin()) {
            auto pv = iter; pv--;
            l = (*iter) - (*pv);
        }
        auto rv = iter; rv++;
        if (rv != nums.end()) {
            r = (*rv) - (*iter);
        }
        ans = max(ans, min(l,r));
    }
    cout << ans << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}