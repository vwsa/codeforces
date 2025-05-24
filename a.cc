#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> sum_of_sqr;
vector<int> summ;
const int mod = 1e9+7;
int add(int x,int y) {
    return ((x % mod) + (y % mod)) % mod;
}
int mi(int x, int y) {
    x = x % mod;
    y = y % mod;
    if (x>=y) {
        return (x - y) % mod;
    } else {
        return (((x + mod)) - (y % mod)) % mod;
    }
}

int mul(int x, int y) {
    return ((x % mod) * (y % mod)) % mod;
}


void solve() {
    int n,k;
    cin >> n >> k;
    if (n == 1) {
        cout << mul(k-1, 1) << endl;
        return;
    }
    int sqrt_n = static_cast<int>(sqrt(static_cast<float>(n)));
    int sum = 0;
    for (int i=2; i <= sqrt_n; i++) {
        int me = 0;
        if (i>k) {
            break;
        }
        int now = n;
        vector<int> v;
        while (now) {
            v.push_back(now % i);
            now /= i;
        }
        int pre = 1;
        while (!v.empty()) {
            int x = v[v.size() - 1];
            me = add(me, mul(x, pre));
            pre = mul(pre, i);
            v.pop_back();
        }
        sum = add(sum, me);
    }
    int l,r;
    l = sqrt_n + 1;
    r = n / (n / l);
    while (1) {
        if (l > k || l > n) {
            break;
        }
        r = n / (n/l);
        r = min(r,k);
        int cnt = (r-l+1);
        int value = (n/l);
        // update sum
        sum = add(sum , mul(n, mi(summ[r],summ[l-1])));
        sum = add(sum, mul(value, add(mi(cnt, sum_of_sqr[r]), sum_of_sqr[l-1])));
        // sum = mi(add(sum, mul(cnt, value)), mul(value, mi(sum_of_sqr[r], sum_of_sqr[l-1])));
        l = r+1;
    }
    if (l <= k) {
        sum = add(sum, mul(add(mi(k,l),1),n));
        // sum = sum + (k - l + 1) * n;
    }
    cout << sum << endl;
}
signed main() {
    summ.push_back(0);
    sum_of_sqr.push_back(0);
    for (int i=1;i<=3e5;i++) {
        int now = mul(i,i);
        summ.push_back(add(summ[i-1], i));
        sum_of_sqr.push_back(add(sum_of_sqr[i-1], now));
    }
    int T;
    cin >> T;
    while (T--) solve();
}