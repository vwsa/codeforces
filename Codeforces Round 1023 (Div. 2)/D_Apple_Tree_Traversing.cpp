#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i=0;i<n;i++) {
        int u,v;
        tree[u].push_back(v); tree[v].push_back(u);
    }
    vector<int> f(n);
    vector<int> used(n);
    vector<int> seen(n);
    vector<array<int,3>> ans;
    while (1){
    seen.assign(n+1, false);
    auto dfs = [&](auto self, int now, int fa) -> pair<int,int> {
        seen[now] = true;
        pair <int,int> ans = {1, now};
        f[now] = fa;
        used[now] = true;
        for (const auto& son: tree[now]) {
            if (son != fa && !used[son]) {
                auto res = self(self, son, now);
                res.first += 1;
                ans = max(ans, res);
            }
        }
        return ans; 
    };

    for (int i = 0; i < n; i++) {
        if (!seen[i] && !used[i]) {
            auto [depth, j] = dfs(dfs, i, -1);
            auto [d, k] = dfs(dfs, j, -1);
            ans.push_back({d, max(j,k), min(j,k)});
            while (k != -1) {
                used[i] = true;
                k = f[k];
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<array<int, 3>>());
    for (auto [x, y, z] : ans){
            cout << x << " " << y << " " << z << " ";
        }
    cout << '\n';
}



}

int main() {
    int T;
    while (T--) {
        solve();
    }
}