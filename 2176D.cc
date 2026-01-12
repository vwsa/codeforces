#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define int long long



void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > n) a[i] = n + 1;
    }
    set<int> st;
    for (int i = 0; i <= n; i++) {
        st.insert(i);
    }
    vector<int> cot(n, 0);

    for (int i = 0; i < k; i++) {
        if (cot[a[i]] == 0) {
            st.erase(a[i]);
        }
        cot[a[i]]++;
    }
    int max_mex = *st.begin();
    for (int l = 1, r = l + k - 1; r < n; l++) {
        if (a[l-1] < n) {    
            cot[a[l-1]]--;
            if (cot[a[l-1]] == 0) {
                st.insert(a[l-1]);
            }
        }
        if (a[r] < n) {
            cot[a[r]]++;
            if (cot[a[r]] == 1) {
                st.erase(a[r]);
            }
        }
        max_mex = max(max_mex, *st.begin());
    }
    cout << min(max_mex, k - 1) << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}