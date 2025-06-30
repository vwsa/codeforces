#include <bits/stdc++.h>
#include <utility>
using namespace std;
void solve() {
    vector<array<int,3>> ans;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    for (int i=0;i<n - 1;i++) {
        for (int j=0;j<n-1-i;j++) {
            if (a[j] > a[j+1]) {
               swap(a[j], a[j+1]);
                ans.push_back({1, j, i+1});
            }
        }
    }

    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1-i;j++) {
            if (b[j] > b[j+1]) {
               swap(b[j], b[j+1]);
                ans.push_back({2, j, i+1});
            }
        }
    }

    for (int i=0;i<n;i++) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            ans.push_back({3, i, i});
        }
    }
    cout << ans.size() << endl;
    for (const auto [a,b,c]: ans) {
        cout << a << " " << b+1 << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}