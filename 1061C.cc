#include <bits/stdc++.h>
#include <clocale>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (auto &x: a) {
        cin >> x;
    }
    vector<int> dp(n+1, 0);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int sqrt_x = floor(sqrt(x));
        vector<int> can_divide;
        for (int j = min(n, sqrt_x); j >= 1; --j) {
            if (x%j != 0) {
                continue;
            }
            can_divide.push_back(j);
            if (j * j != x && x / j <= n) {
                can_divide.push_back(x / j);
            }
        }
        sort(can_divide.begin(), can_divide.end(), std::greater<int>());
        for (const int& j: can_divide) {
            if (j == 1) {
                dp[1] += 1;
                continue;
            }
            if ((j - 1 == 0) || dp[j-1] != 0) {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += dp[i];
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}