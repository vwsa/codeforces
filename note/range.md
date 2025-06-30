```cpp
#include <bits/stdc++.h>
using namespace std;

// 在升序数组 v 中，统计落在区间 (L, R), [L, R], (L, R], [L, R) 内的元素个数。
// 参数说明：
//   - left_closed: 左端点是否闭区间（true 表示 >= L）
//   - right_closed: 右端点是否闭区间（true 表示 <= R）
int count_in_range(const vector<int>& v,
                   int L, int R,
                   bool left_closed,
                   bool right_closed)
{
    // 根据左端点是否闭区间，选择 lower_bound 或 upper_bound
    auto itL = left_closed
               ? lower_bound(v.begin(), v.end(), L)   // >= L
               : upper_bound(v.begin(), v.end(), L);  // > L

    // 根据右端点是否闭区间，选择 upper_bound 或 lower_bound
    auto itR = right_closed
               ? upper_bound(v.begin(), v.end(), R)   // > R
               : lower_bound(v.begin(), v.end(), R);  // >= R

    return max<int>(0, itR - itL); // 防止出现负数
}

int main() {
    vector<int> v = {3, 9, 12, 16};

    // 示例：
    // [9, 16) → 元素为 9, 12
    int c1 = count_in_range(v, 9, 16, true, false);
    // (3, 12] → 元素为 9, 12
    int c2 = count_in_range(v, 3, 12, false, true);
    // (3, 16) → 元素为 9, 12
    int c3 = count_in_range(v, 3, 16, false, false);
    // [3, 16] → 元素为 3, 9, 12, 16
    int c4 = count_in_range(v, 3, 16, true, true);

    cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << endl;
}
