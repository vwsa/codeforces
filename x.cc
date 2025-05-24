#include <bits/stdc++.h>
using namespace std;
#define int long long
int find(void to_next(int&), string s, const vector<int> v, const int from) {
    int res = 0;
    int now = from;
    int tot = 0;
    while (1) {
        to_next(now);
        if (s[now] == 0) {
            break;
        }
        tot += v[now];
        res = max(res, tot);
    }
    return res;
}

void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (auto &x: a){
        cin >> x;
    }
    int maxx = 0;
    int pre_max = 0;
    int pre_min = 0;
    int pre = 0;
    for (int i=0;i<n;i++) {
        if (s[i] == '0') {
            pre = 0;
            pre_max = 0;
            pre_min = 0;
        } else {
            pre = pre + a[i];
            pre_max = max(pre_max, pre);
            pre_min = min(pre_min, pre);
        }
        maxx = max(maxx, pre_max - pre_min);
    }
    if (k == 0 && maxx != k) {
        cout << "NO" << endl;
        return;
    }
    if (maxx < k) {
        cout << "NO" << endl;
        return;
    }
    // find best answer
    {
        for (int i=0;i<n;i++) {
            if (s[i] == '0') {
                int lmax = find([](int& now) {
                    now -= 1;
                }, s, a, i);

                int rmax = find([](int& now) {
                    now += 1;
                }, s, a, i);

                cout << k - lmax - rmax << endl;
                return;
            }
        }
    }

    return;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}