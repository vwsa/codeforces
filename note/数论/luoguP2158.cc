#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> euler(n+1,0);
    vector<int> p;
    euler[1] = 1;
    for (int i=2;i<=n;i++) {
        if (euler[i] == 0) {
            euler[i] = i - 1;
            p.push_back(i);
        }
        for (const auto prime: p) {
            int v = prime * i;
            if (v > n) break;
            if (i % prime == 0) {
                euler[v] = prime * euler[i];
                break;
            } else {
                euler[v] = (prime - 1) * euler[i];
            };
        }
    }
    for (int i=1;i<=n;i++) {
        euler[i] = euler[i] + euler[i-1];
    }
    int ans = (euler[n-1] - euler[1]) * 2 + 2 + 1;
    cout << ans << endl;
    return 0;
}