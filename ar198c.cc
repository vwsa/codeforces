// #include <bits/stdc++.h>
// using namespace std;

// void swap(vector<pair<int,int>>& ans, int i, int j) {
//     ans.push_back({1, i})
// }

// void add_left(vector<pair<int,int>>& ans, int i) {
//     ans.push_back({i, i+1});
//     ans.push_back({i+1, i+2});
//     ans.push_back({i, i + 2});
// }
// int main() {
//     vector<pair<int,int>> ans;
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     vector<int> b(n);
//     for (auto &x: a) {
//         cin >> x;
//     }
//     for (auto &x: b) {
//         cin >> x;
//     }
//     int diff = 0;
//     for (int i=0;i<n;i++){
//         diff += (a[i] - b[i]);
//     }
//     if (diff != 0) {
//         cout << "No" << endl;
//         return 0;
//     }

//     if (n == 2) {
//         if ((a == b)) {
//             cout << "Yes" << endl;
//             cout << 0 << endl;
//         } else if (a[0] + 1 == b[1]) {
//             cout << "Yes" << endl;
//             cout << 1 << endl;
//             cout << "1 2" << endl;
//         } else {
//             cout << "No" << endl;
//         }
//         return 0;
//     }

//     for (int i=0;i<=n-3;i++) {
//         if (a[i] == b[i]) {
//             continue;
//         }
//         while (a[i] > b[i]) {
//             cut_left(ans, i);
//             int tmp = a[i+1];
//             a[i] -= 1;
//             a[i+1] = a[i+2];
//             a[i+2] = tmp + 1;
//         }
//         while (a[i] < b[i]) {
//             add_left(ans, i);
//             int tmp = a[i+1];
//             a[i] += 1;
//             a[i+1] = a[i+2] - 1;
//             a[i+2] = tmp;
//         }
//     }
//     // cout << ans.size() << endl;
//     // for (int i=0;i<n;i++) {
//     //     cout << a[i] << " ";
//     // }
//     // cout << endl;
//     if (a[n-2] >= a[n-1]) {
//         ans.push_back({n-2, n-1});
//         int tmp = a[n-1];
//         a[n-1] = a[n-2] + 1;
//         a[n-2] = tmp - 1;
//     }
//     while (a[n-1] != b[n-1]) {
//         if (a[n-2] + 1 == b[n-1]) {
//             ans.push_back({n-2, n-1});
//             break;    
//         }
//         ans.push_back({n-2, n-1});
//         ans.push_back({n-3, n-1});
//         ans.push_back({n-3, n-2});
//         ans.push_back({n-3, n-1});
//         a[n-2] += 1;
//         a[n-1] -= 1;
//     }
//     cout << "Yes" << endl;
//     cout << ans.size() << endl;
//     for (const auto &[a,b]: ans) {
//         cout << a+1 << " " << b+1 << endl;
//     }
//     return 0;
// }