
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x,y,z;
    cin >> x >> y >> z;
    if (y > 2 * x) {
        cout << "No" << endl;
        return;
    }
    if (y % 2 == 0) {
        if (z <= x) {
            cout << "Yes" << endl;
            return;
        } else {
            cout << "No" << endl;
            return;
        }
    } else {
        if (z == 0) {
            cout << "No" << endl;
            return;
        } else {
            if (z <= x) {
                cout << "Yes" << endl;
                return;
            } else {
                cout << "No" << endl;
                return;
            }
        }
    }
    
}
int main(){
    int T;
    cin >> T;
    while (T--) solve();
}