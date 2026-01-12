#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define int long long



void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n+1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n+1, 0);
    vector<int> fa(n+1, 0);
    queue<pair<int,int>> q;
    q.push({0,1});
    while (!q.empty()) {
        auto [pre, now] = q.front();
        q.pop();
        d[now] = d[pre] + 1;
        fa[now] = pre;
        for (const auto& x: g[now]) {
            if (d[x] == 0) {
                q.push({now, x});
            }
        }
    }
    vector<int> cnt_d(n+1, 0);
    vector<set<int>> fa_of_d(n+1, set<int>());
    for (int i = 1; i <= n; i++) {
        cnt_d[d[i]]++;
        fa_of_d[d[i]].insert(fa[i]);
    }

    int max_cnt_d = *max_element(cnt_d.begin(), cnt_d.end());
    bool flag = 1;
    vector<int> target_d;
    for (int i = 1; i <= n; i++) {
        if (cnt_d[i] == max_cnt_d) {
            target_d.push_back(i);
        }
    }
    int add = 0;
    for (const auto td: target_d) {
        if (fa_of_d[td].size() == 1) {
            add = 1;
            break;
        }
    }
    cout << max_cnt_d + add << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}