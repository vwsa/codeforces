#include <bits/stdc++.h>
using namespace std;
const int mod = 998'244'353;
int mul(int a, int b) {
    return ((a % mod) * (b % mod)) % mod;
}
int add(int a,int b) {
    return ((a % mod) + (b % mod)) % mod;
}
void solve() {
    int n,k;
    cin >> n >> k;
    // <= sqrt(n)
    int sqrtn = sqrt(n);
    int ans = 0;
    int a[30];
    for (int p=2;p<=sqrtn;p++) {
        int len = 0;
        int res = n;
        while (n) {
            a[len++] = (res & 1);
            res /= 2;
        }
        int reversed_value = 0;
        int now = 1;
        for (int i=len-1;i>=0;i--) {
            reversed_value += now * a[i];
            now *= p;
        }
        ans += reversed_value;
    }
    
}
int main() {
    solve();
}