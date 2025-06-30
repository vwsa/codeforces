#include <bits/stdc++.h>
using namespace std;
void solve() {
    auto check = [&](int l,int r,const string& s, const string& t) -> bool {
        map<int,int> mp,mp2;
        for (int i=l;i<r;i++) {
            mp[s[i]]++;
            mp2[t[i]]++;
        }
        return mp == mp2;
    };
    auto check2 = [&](int l,int r, const string& s, const string& t) -> bool {
        for (int i=l;i<r;i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    };
    int n, k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    if (k <= n / 2) {
        if  (check(0,n,s,t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (check2(max(n-k,0),min(k,n), s,t) && check(0,n,s,t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl; 
        }
    }

}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}