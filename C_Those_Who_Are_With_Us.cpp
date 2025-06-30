#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    int maxx = 0;
    int a[n][m];
    memset(a, 0,sizeof(a));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
            maxx = max(maxx, a[i][j]);
        }
    }
    vector<pair<int,int>> pp;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (a[i][j] == maxx) {
                pp.push_back({i,j});
            }
        }
    }
    int nn = pp.size();
    int first_in_row = false;
    {
        vector<int> tagged(nn, 0);
        int first_unimplemented = -1;
        for (int i=0;i<nn;i++) {
            if (pp[0].first == pp[i].first) {
                tagged[i] = 1;
            } else {
                if (first_unimplemented == -1) {
                    first_unimplemented = i;
                }
            }
        }

        if (first_unimplemented != -1) { for (int i=0;i<nn;i++) {
            if (tagged[i] == 0 && pp[first_unimplemented].second == pp[i].second) {
                tagged[i] = 1;
            }
        }}

        if (count(tagged.begin(), tagged.end(), 1) == nn) {
            first_in_row = true;
        }
    }
    int first_in_column = false;
    {
        vector<int> tagged(nn, 0);
        int first_unimplemented = -1;
        for (int i=0;i<nn;i++) {
            if (pp[0].second == pp[i].second) {
                tagged[i] = 1;
            } else {
                if (first_unimplemented == -1) {
                    first_unimplemented = i;
                }
            }
        }
        if (first_in_column != -1) { for (int i=0;i<nn;i++) {
            if (tagged[i] == 0 && pp[first_unimplemented].first == pp[i].first) {
                tagged[i] = 1;
            }
        }}

        if (count(tagged.begin(), tagged.end(), 1) == nn) {
            first_in_column = true;
        }
    }
    if (first_in_column || first_in_row) {
        maxx --;
    }
    cout << maxx << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}