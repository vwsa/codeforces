    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    void solve() {
        int n,c;
        cin >> n;
        deque<int> a;
        for (int  i=0;i<n;i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int minn = a[0];
        for (int i=1;i<n;i++) {
            if (a[i] <= max(2 * minn - 1, minn)) {
                minn = min(minn, a[i]);
                continue;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    signed main() {
        int T;
        cin >> T;
        while (T--) solve();
    }