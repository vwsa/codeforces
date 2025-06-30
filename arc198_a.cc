
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if ( n == 1 ) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    cout << n / 2 << endl;
    for (int i=2;i<=n;i+=2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}