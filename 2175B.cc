#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9;
const int MAXN = 4e5;
vector<int> ans = {0};
vector<int> pre = {0};
void solve() {
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> res(n+1, 0);
    for (int i = 1; i <= n; i++) {
        res[i] = ans[i];
    }
    res[r] = pre[r-1] ^ pre[l-1];
    for (int i = 1; i <= n;i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
signed main() {
    int T;
    cin >> T;
    vector<int> prime = {0, 2, 3, 5, 7, 11, 13,17};
    for (int i = 1; i <= MAXN; i++) {
        int res = 1;
        for (int j = 1; j < prime.size(); j++) {
            if (i % prime[j] == 0) {
                res = res | (1 << j);
            }
        }
        ans.push_back(res);
        pre.push_back(pre[i-1] ^ ans[i]);
    }
    while (T--) solve();
}