#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMaxN = 1e6 + 69;
vector<int64_t> c(kMaxN);

void precalc() {
  c[0] = c[1] = 0;
  for (int i = 2; i < kMaxN; ++i) {
    c[i] = c[i - 1];
    int x = i;
    while (x % 2 == 0) {
      x /= 2, c[i]++;
    }
  }
}

void solve() {
  int n, k;
  cin >> n >> k;

  --n;
  for (int i = 0; i <= n; ++i) {
    cout << k * (c[n] == c[i] + c[n - i]) << " \n"[i == n];
  }
}

signed main() {
    ios::sync_with_stdio(false);
    precalc();
    cin.tie(0);
    cout.tie(0);
    long long T;
    cin >> T;
    while (T--) solve();
}
/*
(a / 2)^2 * b
---___---
*/