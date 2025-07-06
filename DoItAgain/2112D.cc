#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> deg(n+1, 0);
    vector<vector<int>> to(n+1);
    for (int i=0;i<n;i++) {
        int u,v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        to[u].push_back(v); to[v].push_back(u);
    }
    int st = -1;
    for (int i=1;i<=n;i++) if (deg[i] == 2) {
        st = i;
        break;
    }
    if (st == -1) {
        cout << "NO" << endl;
        return;
    }
    vector<pair<int,int>> ans;
    int fa = to[st][0];
    auto dfs = [&](auto self, int now, int msg, int fa) -> void {
        if (fa != -1) {
            if (msg == 0) {
                ans.push_back({fa, now});
            } else {
                ans.push_back({now, fa});
            }
        }
        for (const auto& son: to[now]) {
            if (son == fa) {
                continue;
            } else {
                if (now == st) {
                    self(self, son, msg, now);
                } else {
                    self(self, son, msg^1, now);
                }
            }
        }
    };
    dfs(dfs, fa, 0, -1);
    cout << "YES" << endl;
    for (const auto& [a,b]: ans) {
        cout << a << " " << b << endl;
    }
    return;
}
int main() {
    int T;
    while (T--) solve();
}