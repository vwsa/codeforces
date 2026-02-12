#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[n] = n;
    int x = -1;
    for (int i = n-1; i >= 1; i--) {
        a[i] = a[i+1] + x * i;
        x *= -1;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {

}