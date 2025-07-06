#include <bits/stdc++.h>
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
    int a,b,x,y; cin >> a >> b >> x >> y;
    if(b<a){
        if(b==a-1&&(a^b)==1) cout << y << endl;
        else cout << -1 << endl;
        return;
    }
    int val1=b-a,val2=b/2-a/2;
    cout << (val2*x+(val1 - val2)*min(x,y)) << endl;
    
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}