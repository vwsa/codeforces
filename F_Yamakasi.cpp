#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,s,x;
    int ans = 0;
    cin >> n >> s >> x;
    vector<int> v(n+1);
    // value, id
    vector<pair<int,int>> maxx;
    int p = 0;
    map<int, vector<int>> pre;
    bool in_maxx = false;
    pre[0].push_back(0);
    for (int i=1;i<=n;i++) {
        cin >> v[i];
        p += v[i];
        pre[p].push_back(i);
        while (!maxx.empty() && maxx[maxx.size() - 1].first <= v[i]) {
            if (maxx[maxx.size() - 1].first == x) {
                in_maxx = false;
            }
            maxx.pop_back();
        }
        maxx.push_back({v[i], i});
        if (v[i] == x) {
            in_maxx = true;
        }
        
        if (in_maxx == false) {
            continue;
        }
        int index = upper_bound(maxx.begin(), maxx.end(), pair<int,int>{x, LONG_LONG_MAX}, [&](const pair<int,int> &a, const pair<int,int> &b) -> bool {
            return a > b;
        }) - maxx.begin();

        int posr = maxx[index].second;
        int posl;
        {
            if (index == 0) {
                posl = 0;
            } else {
                posl = maxx[index - 1].second;
            }
        }
        int target_pre = p - s;
        // (posl, posr] who satisfy max == x
        // the first index should be >= posl as we are finding a pre-sum value
        int count_n_l = lower_bound(pre[target_pre].begin(), pre[target_pre].end(), posl) - pre[target_pre].begin();
        int count_n_r = lower_bound(pre[target_pre].begin(), pre[target_pre].end(), posr) - pre[target_pre].begin();
        ans += (count_n_r - count_n_l);
    }
    cout << ans << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}