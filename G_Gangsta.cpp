#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Handler {
    int zero_id;
    vector<int> data;
    void push(int x) {
        data.push_back(x);
    }
};
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tot = 0;
    for (int i=1;i<=n;i++) {
        tot += (n-i+1)*i;
    }
    vector<int> pre(n+1,0);
    for (int i=1;i<=n;i++) {
        if (s[i-1] == '0') pre[i] = pre[i-1] - 1;
        else pre[i] = pre[i-1] + 1;
    }
    sort(pre.begin(), pre.end());
    int pre_sum = 0;
    for (int i=1;i<=n;i++) {
        pre_sum += pre[i-1];
        tot += (pre[i] * i - pre_sum);
    }
    cout << tot / 2 << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}