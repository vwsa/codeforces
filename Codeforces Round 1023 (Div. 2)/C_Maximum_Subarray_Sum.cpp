#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int find(void to_next(int&), string s, const vector<int> v, const int from) {
    int res = 0;
    int now = from;
    int tot = 0;
    while (1) {
        to_next(now);
        if (now < 0 || now >= s.length() || s[now] == '0') {
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
    auto count = std::count_if(s.begin(), s.end(), [](char x){return x == '0';});
    vector<int> a(n);
    for (auto &x: a){
        cin >> x;
    }
    int maxx = LONG_LONG_MIN;
    int pre_max = 0;
    int pre_min = 0;
    int pre = 0;
    for (int i=0;i<n;i++) {
        if (s[i] == '0') {
            pre_max = 0;
            pre_min = 0;
            pre = 0;
        } else {
            pre = pre + a[i];
            maxx = max(maxx, pre - pre_min);
            pre_min = min(pre_min, pre);
        }
    }
    if (count == 0 && maxx != k) {
        cout << "NO" << endl;
        return;
    }
    if (maxx > k) {
        cout << "NO" << endl;
        return;
    }
    // find best answer
    {
        for (int i=0;i<n;i++) {
            if (s[i] == '0') {
                a[i] =  -500000000000000000;
            }
        }
        for (int i=0;i<n;i++) {
            if (s[i] == '0') {
                int lmax = find([](int& now) {
                    now -= 1;
                }, s, a, i);

                int rmax = find([](int& now) {
                    now += 1;
                }, s, a, i);
                a[i] = k - lmax - rmax; 
                break;
            }
        }
        cout << "YES" << endl;
        for (const auto x: a) {
            cout << x << " ";
        }
        cout << endl;
    }

    return;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}