#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n,k;
const int DELTA = 1000;
bitset<2001> dp[2];
int main() {
    cin >> n >> k;
    vector<int> a(k, 0);
    for (auto& x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    k = a.size();
    for (int i = 0; i < k; i++) {
        a[i] -= n;
    }
    int t = 0;
    dp[1][DELTA] = 1;
    for (int i = 1; i <= 2005; i++) {
        for (int j = 0; j < k; j++) {
            if (a[j] < 0) {
                dp[t] |=  dp[1-t] >> (-a[j]);
            } else {
                dp[t] |= dp[1-t] << a[j];
            }
        }
        if ((dp[t][DELTA]) != 0) {
            cout << i << endl;
            return 0;
        }
        t = 1 - t;
        dp[t].reset();
    }
    cout << -1 << endl;
}