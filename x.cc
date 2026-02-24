#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    string s[4];
    s[0] = "abba";
    s[1] = "abab";
    s[2] = "baba";
    s[3] = "baab";
    array<int,4> check = {1,1,1,1};
    for (int i = 0; i < 3; i++) {
        if (str[i] == '?') {continue;}
        for (int j = 0; j < 3; j++) {
            if (str[i] != s[j][i]) {
                check[j] = 0;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (check[i]) return true;
    }
    return false;
}
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 1) {
        if (s[0] == 'b') {
            cout << "NO" << endl;
            return;
        } 
        s = s.substr(1, n-1);
    }

    for (int i = 0; i < s.length(); i += 2) {
        string substr = s.substr(i, 2);
        if (substr == "bb" || substr == "aa") {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}