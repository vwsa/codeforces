#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long
const int MOD = 998244353;
int quickpowmod(int a,int b) {
    int ans=1;
    while(b) {
        if(b&1) ans=(ans*a)%MOD;
        b>>=1;
        a=(a*a)%MOD;
    }
    return ans;
}

int inv(int a) {
    return quickpowmod(a, MOD-2);
}
void solve() {
    map<pair<int,int>, int> exist;
    map<pair<int,int>, int> non_exist;
    map<pair<int,int>, int> non_exist_cal;
    map<pair<int,int>, int> inv_non_exist;
    int n,m;
    cin >> n >> m;
    vector<array<int,4>> a(n);
    for (int i=0;i<n;i++) {
        int l,r,p,q;
        cin >> l >> r >> p >> q;
        a[i] = {l,r,p,q};
        exist[{p,q}] =  (p * inv(q)) % MOD;
        non_exist[{p,q}] = ((q - p) * inv(q)) % MOD;
        non_exist_cal[{p,q}] ++;
        inv_non_exist[{p,q}] = (inv(q - p) * q) % MOD;
    }
    sort(a.begin(), a.end());
    auto a_iter = a.begin();
    vector<int> dp(m+1, 0);
    priority_queue<array<int,4>> to_handle;
    int nothing_exist = 1;
    for (const auto &[k,v]: non_exist) {
        int b = quickpowmod(v, non_exist_cal[k]);
        nothing_exist = (nothing_exist * b) % MOD;
    }
    dp[0] = 1;
    for (int i=1;i<=m;i++) {
        while (a_iter != a.end() &&  (*a_iter)[0] <= i) {
            auto [l,r,p,q] = *a_iter;
            to_handle.push({-r,l,p,q});
            a_iter++;
        }
        while (!to_handle.empty() && to_handle.top()[0]*-1 == i) {
            auto [neg_r, l, p, q] = to_handle.top(); to_handle.pop();
            int r = -neg_r;
            // 
            if (l == 1) {
                dp[r] += ((((((dp[l-1] * nothing_exist) % MOD) * inv_non_exist[{p,q}]) % MOD) * exist[{p,q}]) % MOD);
                dp[r] = dp[r] % MOD;
            } else {
                dp[r] += ((((dp[l-1] * inv_non_exist[{p,q}]) % MOD) * exist[{p,q}]) % MOD);
                dp[r] = dp[r] % MOD;
            }
        }
    }
    cout << dp[m] << endl;
    return;
}
signed main() {
    int T;
    // cin >> T;
    T = 1;
    while (T--) solve();
}