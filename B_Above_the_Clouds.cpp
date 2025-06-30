#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n >= 60) {
        cout << "Yes" << endl;
        return;
    }
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            // [0,i) [i, j) [j, n)
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, j-i);
            string s3 = s.substr(j,n-j);
            string ss = s1 + s3;
            if (ss.find(s2) != std::string::npos) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}