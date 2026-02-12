#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> t(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u,v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> son(n+1);
    auto dfs = [&](auto&& self, int now, int fa) -> void {
        int son_cnt = 0;
        for (const auto v: t[now]) {
            if (v != fa) {
                son[now]++;
                self(self, v, now);
            }
        }
    };
    dfs(dfs, 1, 0);
    vector<array<int, 3>> f(n+1);
    auto gogo = [&](auto&& self, int now, int fa) -> void {
        if (son[now] == 0) {
            f[now][1] = 1;
        } else {
            for (const auto v: f[now]) {
                if (v == fa) {
                    continue;
                }
                
            }
        }
    };
}
int main() {

}