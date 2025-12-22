#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> odd, eve;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) eve.push_back(x); else odd.push_back(x);
    }
    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());
    sort(eve.begin(), eve.end());
    reverse(eve.begin(), eve.end());
    vector<int> x;
    if (odd.empty()) {
        for (int i = 0; i < n; i++) {
            cout << "0 ";
        }
        cout << endl;
        return;
    }

    x.push_back(odd[0]);
    int odd_size = odd.size() - 1;
    for (const auto v: eve) {
        x.push_back(v);
    }
    for (int i = 1; i < x.size(); i++) {
        x[i] += x[i-1];
    }
    while (odd_size > 0) {
        if (odd_size >= 2) {
            x.push_back(x.size() >= 2?x[x.size() - 2]:0);
            x.push_back(x[x.size() - 2]);
            odd_size -= 2;
        } else {
            x.push_back(0);
            odd_size -= 1;
            break;
        }
    }
    
    for (const int v: x) {
        cout << v << " ";
    }
    cout << endl;
    return;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}