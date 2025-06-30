#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    int now = 0;
    int count = 0;
    for (const char &x: s) {
        if (x == ')') now--;
        if (x == '(') now++;
        if (now == 0) {
            count++;
        }
    }
    if (count != 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}