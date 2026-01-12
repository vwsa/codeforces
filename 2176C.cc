#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int S,D;
    vector<int> s, d;
    for (int i = 0; i < n; i++) {
        if (a[i]%2==0) {
            s.push_back(a[i]);
        } else {
            d.push_back(a[i]);
        }
    }
    S = s.size(); D = d.size();
    if (D == 0) {
        for (int k = 1; k <= n; k++) {
            cout << "0 ";
        }
        cout << endl;
        return;
    }
    sort(s.begin(), s.end(), std::greater<int>());
    int d_max = *max_element(d.begin(), d.end());
    vector<int> s_pre = {0};

    for (const auto x: s) {
        s_pre.push_back(s_pre[s_pre.size() - 1] + x);
    }

    for (int k = 1; k <= n; k++) {
        int d_1 = max((int)ceil((k - S - 1.0) / 2.0), 0LL);
        int d_cnt = d_1 * 2 + 1;
        if (d_cnt > D) {
            cout << "0 ";
            continue;
        }
        int s_cnt = k - d_cnt;
        if (s_cnt < 0) {
            cout << 0 << " ";
        } else {
            cout << s_pre[s_cnt]  + d_max << " ";
        }
    }
    cout << endl;
    return;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}