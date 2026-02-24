#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> r(n), a(n), p(n+1);
    vector<pair<int, int>> rank;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rank.push_back({a[i], i});
    }
    sort(rank.begin(), rank.end(), std::greater<pair<int,int>>());
    for (int i = 0; i < n; i++) {
        r[i] = i;
    }
    for (const auto [v, id]: rank) {
        int x = id + 1;
        while (x < n && a[x] == v + 1) {
            x = r[x] + 1;
        }
        r[id] = x - 1;
    }

    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        p[i] = p[r[i] + 1] + (n - r[i] - 1) + (r[i] - i + 1);
        ans += p[i];
    }
    cout << ans << endl;
    return;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}