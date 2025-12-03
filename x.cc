#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> gsl;
    vector<int> gsr;
    deque<int> gs;
    for (int i = 1; i <= n; i++) {
        int guess;
        cin >> guess;
        if (guess < l) {
            gsl.push_back(guess);
            continue;
        }
        if (guess > r) {
            gsr.push_back(guess);
            continue;
        }
        gs.push_back(guess);
    }
    sort(gs.begin(), gs.end());
    
    int win = 0;

    while (gsl.size() > gsr.size() && !gs.empty()) {
        gsr.push_back(gs[gs.size() - 1]);
        gs.pop_back();
    }
    while (gsl.size() < gsr.size() && !gs.empty()) {
        gsl.push_back(gs[0]);
        gs.pop_front();
    }

    
    vector<int> ll;
    vector<int> rr;
    int len = gs.size();
    int s = 0, t = len - 1;
    while (s < t) {
        gsl.push_back(gs[s]);
        gsr.push_back(gs[t]);
        ++s; --t;
    }
    int sum_l = 0;
    for (int i = 0; i < gsl.size(); i++) {
        sum_l = sum_l - gsl[i];
    }
    int sum_r = 0;
    for (int i = 0; i < gsr.size(); i++) {
        sum_r = sum_r + gsr[i];
    }
    int c_l = gsl.size();
    int c_r = gsr.size();
    win += (sum_r + sum_l);
    if (c_l > c_r) {
        win += l * (c_l - c_r);
    } else {
        win += r * (c_l - c_r);
    }
    cout << win << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}