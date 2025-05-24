#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n;i++) {
        int x;
        cin >> x; v.push_back(x);
    }

    sort(v.begin(), v.end());

    vector<pair<int,int>> a;
    for (const auto& x: v) {
        if (a.empty()) {
            a.push_back({x, 1});
            continue;
        }
        if (a.back().first == x) {
            a.back().second += 1;
        } else {
            a.push_back({x, 1});
        }
    }
    int last_num = -1;
    int last_cnt = -1;
    for (const auto &[num, exist]: a) {
        if ((num - last_num - 1) * 2 <= last_cnt) {
            last_cnt = last_cnt - (num - last_num - 1) * 2 + exist - 2;
            last_num = num;
        } else {
            if (last_cnt % 2 != 0 && last_cnt != -1) {
                cout << "NO" << endl;
                return;
            }
            last_num = num;
            last_cnt = exist - 2;
        }
        if (last_cnt < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}
int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}