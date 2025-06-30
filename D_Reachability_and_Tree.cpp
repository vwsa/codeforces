#include <bits/stdc++.h>
#include <ostream>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int max_dist, farthest_node;



void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    for (int i=1;i<n;i++) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int target = -1;
    for (int i=1;i<=n;i++) {
        if (tree[i].size() == 2) {
            target = i;
        }
    }
    if (target == -1) {
        cout << "NO" << endl;
        return;
    } 

    int root = tree[target][0];
    vector<pair<int,int>> res;
    auto dfs = [&](auto self, int now, int fa, bool up) -> void {
        for (const auto& son: tree[now]) {
            if (son != fa) {
                if (up) {
                    res.push_back({now, son});
                } else {
                    res.push_back({son, now});
                }
                bool next_up = !up;
                if (son == target) {
                    next_up = !next_up;
                }
                self(self, son, now, next_up);
            }
        }
    };
    dfs(dfs, root, -1, 0);
    cout << "YES" << endl;
    for (int i=0;i<res.size();i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}