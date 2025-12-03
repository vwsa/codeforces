#include <bits/stdc++.h>
using namespace std;
int mp[26][26]; // first, last, len
int main() {
    int n;
    cin >> n;
    vector<string> s;
    
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        s.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int cur_first = s[i][0] - 'a';
        int cur_last  = s[i][s[i].size() - 1] - 'a';
        vector<int> v('z'-'a' + 1, 0);
        for (int j = 0; j <= 'z' - 'a'; j++) {
            int prev_first = j;
            if (mp[prev_first][cur_first] > 0) {
                v[prev_first] = max(mp[prev_first][cur_last], (int)mp[prev_first][cur_first] + (int)s[i].size());
            }
        }
        for (int j = 0; j <= 'z' - 'a'; j++) {
            mp[j][cur_last] = max(mp[j][cur_last], v[j]); 
        }
        mp[cur_first][cur_last] = max(mp[cur_first][cur_last], (int)s[i].size());
    }
    int res = 0;
    for (int i = 0 ; i <= 'z' - 'a'; i++) {
        res = max(res, mp[i][i]);
    }
    cout << res << endl;
}