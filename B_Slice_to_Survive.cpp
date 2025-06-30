#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int n,m, a, b;
    cin >> n >> m >> a >> b;

    int n2 = min(a, n - a + 1);
    int m2 = min(b, m - b + 1);
    auto work = [&](int n,int m) -> int {
        return ceil(log2(double(n))) +  ceil(log2(double(m)));
    };
    int count = min(work(n2, m), work(n, m2));
    count += 1;
    cout << count << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}


