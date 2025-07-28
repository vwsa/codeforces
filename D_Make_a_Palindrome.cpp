#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using u64 = unsigned long long;
bool check_pd(vector<int>& x) {
    int len = x.size();
    for (int i=0;i<len/2;i++) {
        if (x[i] != x[len-i-1]) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> A(n,0);
    vector<int> sorted(n,0);
    vector<int> a;
    vector<int> aa;
    for (int i=0;i<n;i++) {
        cin >> A[i]; A[i]--; sorted[i] = A[i];
    }
    sort(sorted.begin(), sorted.end());
    int bord = sorted[k-1];
    // for (int i=0;i<n;i++) {
    //     if (v[i] <= thres) {
    //         a.push_back(v[i]);
    //     }
    //     if (v[i] < thres) {
    //         aa.push_back(v[i]);
    //     }
    // }
    // if (check_pd(aa) == false) {
    //     cout << "NO" << endl;
    //     return;
    // }
    // int l = 0, r = a.size() - 1;
    // while (l < r) {
    //     while (a[l] == thres && l < r) l++;
    //     while (a[r] == thres && l < r) r--;
    //     if (l != r) {
    //         l++; r--;
    //     }
    // }
    // int can_insert = 0;
    // if (a[l]==thres){
    //     l--;
    //     while (a[l] == thres && l>=0) {
    //         l--;
    //         can_insert++;
    //     }
    //     while (a[r] == thres && r<=n-1) {
    //         r++;
    //         can_insert++;
    //     }
    // }
    // l -= 1;
    // r += 1;
    // while (l >= 0 && r <= n - 1) {
    //     int left = 0;
    //     int right = 0;
    //     while (a[l] == thres && l >= 0) {
    //         l--;
    //         left++;
    //     }
    //     while (a[r] == thres && r <= n-1) {
    //         r++;
    //         right++;
    //     }
    //     can_insert += min(left, right) * 2;   
    //     l -= 1;
    //     r += 1;
    // }
    // if (aa.size() + can_insert >= k-1) {
    //     cout<<"YES"<<endl;
    // }else {
    //     cout<<"NO"<<endl;
    // }
    vector<i64> F, G = {0};
    for(i64 a : A){
        if(a < bord){ F.push_back(a); G.push_back(0); }
        if(a == bord) G.back()++;
    }
    if(!equal(F.begin(), F.end(), F.rbegin())){ cout << "NO\n"; return; }
    i64 kyoyou = 0;
    for(i64 i=0; (i+1)*2<=(i64)G.size(); i++) kyoyou += min(G[i], G[G.size()-1-i]) * 2;
    if(G.size()%2 == 1) kyoyou += G[G.size()/2];
    if(i64(F.size()) + kyoyou < k - 1){ cout << "NO\n"; return; }
    cout << "YES\n";

}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}