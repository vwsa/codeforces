#include <bits/stdc++.h>
#include <queue>
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    if (n < m || m > n * (n-1) / 2) {
        cout << "-1" << endl;
        return;
    } 
    int good_remain = n;
    set<int> s;
    vector<int> tree;
    s.clear();
    while (m >= good_remain) {
        tree.push_back(m);
        m -= maxx;
        maxx -= 1;
    }
    int mm = m;
    if (m != 0) {
        tree.push_back(m);
    }
    for (int i=1;i<=n;i++) {
        if (tree.size() == n) {break;}
        if (i == )
    }

    
    
    
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}