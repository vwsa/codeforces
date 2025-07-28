#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    int gcd = 0;
    for (int i=0;i<k;i++) {
        int x;
        cin >> x;
        gcd = __gcd(gcd, x);
    }
    cout << abs(gcd) << endl;
}