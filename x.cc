#include <bits/stdc++.h>
using namespace std;
#define int long long
int p2[31];
void solve() {
    int n,k;
    cin >> n >> k;
    if ((k % 2) == 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " ";
        }
        cout << endl;
        return;
    }
    int x = 0, y = 0;
    int step = -1;
    for (int i = 30; i >= 0; i--) { // x > y
        int check = (1 << i);
        if ((check & n) != 0) {
            if (step == -1) {
                x |= check;
                // y same
                step = 0;
                continue;
            } else if (step == 0) {
                // x same as x < n
                y |= check;
                step = 1;
                continue;
            } else if (step == 1) {
                y |= check;
                continue;
            }
        } else {
            if (step == -1) {
                continue;
            } else if (step == 0) {
                continue;
            } else if (step == 1) {
                x |= check;
                y |= check;
                continue;
            }
        }
    }
    vector<int> new_ans;
    int cnt = 0;
    int i_pre = -1;
    int k_res = k - 2;
    for (int i = 30; i >= 0; i--) {
        if ((n & (1 << i)) != 0) {
            if (k_res <= 0) {
                break;
            }
            cnt ++;
            if (cnt == 3) {
                i_pre = i;
            } else if (cnt >= 4) {
                k_res -= 2;
                int bd = n;
                int bd2 = n;
                x |= (1 << i);
                x |= (1 << i_pre );
                bd -= (1 << i);
                bd2 -= (1 << i_pre);
                bd |= (p2[i] - 1);
                bd2 |= (p2[i] - 1);
                cnt = 2;
                new_ans.push_back(bd);
                new_ans.push_back(bd2);
            }
        }
    }
    int now = 2;
    cout << x << " " << y << " ";
    while (1) {
        if (now >= k) {break;}
        if (new_ans.empty()) {
            cout << n << " ";
            now += 1;
        } else {
            cout << new_ans[new_ans.size() - 1] << " ";
            new_ans.pop_back();
            cout << new_ans[new_ans.size() - 1] << " ";
            new_ans.pop_back();
            now += 2;
        }
    }
    cout << endl;
    return;
}
signed main() {
    p2[0] = 1;
    for (int i = 1; i < 31; i++) {
        p2[i] = 2 * p2[i-1];
    }
    int T;
    cin >> T;
    while (T--) solve();
}