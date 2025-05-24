#include <bits/stdc++.h>
using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector <bool> used(n + 1, false), seen(n + 1, false);
        vector <array<int, 3>> ans;
        vector <int> p(n + 1, -1);
        
        while (true){
            if (count(used.begin() + 1, used.end(), false) == 0){
                break;
            }
            seen.assign(n + 1, false);
            
            auto dfs = [&](auto self, int u, int par) -> pair<int, int>{
                pair <int, int> ans = {1, u};
                p[u] = par;
                seen[u] = true;
                
                for (int v : adj[u]){
                    if (v != par && !used[v]){
                        auto pi = self(self, v, u);
                        pi.first += 1;
                        ans = max(ans, pi);
                    }
                }
                
                return ans;
            };
            
            for (int i = 1; i <= n; i++) if (!used[i] && !seen[i]){
                auto [d1, j] = dfs(dfs, i, -1);
                auto [d2, k] = dfs(dfs, j, -1);
                ans.push_back({d2, max(j, k), min(j, k)});
                
                while (k != -1){
                    used[k] = true;
                    k = p[k];
                }
            }
        }
        
        sort(ans.begin(), ans.end(), greater<array<int, 3>>());
        for (auto [x, y, z] : ans){
            cout << x << " " << y << " " << z << " ";
        }
        cout << '\n';
    }
    return 0;
}