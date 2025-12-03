#include <bits/stdc++.h>
#include <deque>
using namespace std;
void solve() {
    int n,c;
    cin >> n;
    deque<int> a;
    for (int  i=0;i<n;i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    string ret;
    while (1) {
        if (a.size() < 3) {
            break;
        }
        int a1 = a[0];
        int a2 = a[1];
        int a3 = a[a.size() - 1];
        a.pop_front();a.pop_front();a.pop_back();
        if (a1 > a2 && a2 > a3) {
            ret.push_back('L');
            ret.push_back('R');
            ret.push_back('L');
        }
        if (a1 > a3 && a3 > a2) {
            ret.push_back('L');
            ret.push_back('L');
            ret.push_back('R');
        }
        if (a2 > a1 && a1 > a3) {
            ret.push_back('L');
            ret.push_back('L');
            ret.push_back('R');
        }
        if (a2 > a3 && a3 > a1) {
            ret.push_back('L');
            ret.push_back('L');
            ret.push_back('R');
        }
        if (a3 > a1 && a1 > a2) {
            ret.push_back('L');
            ret.push_back('L');
            ret.push_back('R');
        }
        if (a3 > a2 && a2 > a1) {
            ret.push_back('L');
            ret.push_back('R');
            ret.push_back('L');
        }
    }
    int size = a.size();
    for (int i=0;i<size;i++) ret.push_back('L');
    cout << ret << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}