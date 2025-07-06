#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
struct Handler {
    int zero_id;
    vector<int> data;
    void push(int x) {
        data.push_back(x);
    }
};
void solve() {
    int n;
    int a,b,x,y;
    cin >> n;
    vector<int> v(n);
    cin >> a >> b >> x >> y;
    for (auto& val: v) {
        cin >> val;
    }
    if (n == 1) {
        if ((a-x) * (a-x) + (b-y) * (b-y) == v[0] * v[0]) {
            cout << "Yes" << endl;
            return;
        } else {
            cout << "No" << endl;
            return;
        }
    }

    sort(v.begin(), v.end());
    pair<int,int> p = {abs(v[0] - v[1]),abs(v[0] + v[1])};
    for (int i=2;i<n;i++) {
        int minn = p.first;
        int maxx = p.second;
        if (p.first <= v[i] && v[i] <= p.second) {
            p.first = 0;
            p.second = v[i] + maxx;
        } else {
            p.first = v[i] - p.second;
            p.second = v[i] + p.second;
        }
    }
    double distance = sqrt((a-x) * (a-x) + (b-y) * (b-y));
    if ((double)p.first <= distance && distance <= (double)p.second) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}