#include <bits/stdc++.h>
#include <queue>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v;
    vector<int> p(n+1, 0);
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        v.push_back(x);
        p[x]++;
    }
    int x = 0;
    for (int i=0;i<=n;i++) {
        if (p[i] == 0) {
            x = i;
            break;
        }
    }
    vector<int> total(n+2, 0);
    for (int i=0;i<=x;i++) {
        total[p[i]] ++;
        total[n-i+1] --;
    }
    for (int i=1;i<=n;i++) {
        total[i] = total[i] + total[i-1]; 
    }
    for (int i=0;i<=n;i++) {
        cout << total[i] << " ";
    }
    cout << endl;
    
    
    
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}