#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 100;
int f[maxn],h[maxn], sz[maxn];//每个结点的父亲及树高

//初始化n个元素
void init(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        f[i] = i;
        h[i] = 0;
    }
}

//查询树的根
int find(int x)
{
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);//路径压缩
}

//合并x和y所属的集合
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    int szx = sz[x];
    int szy = sz[y];
    if(x == y) return;
    //树高优化，由于find后已经路径压缩，所以x与y的高度差最多为1
    if(h[x] < h[y]) f[x] = y;//这里树高相差1（一个为1，一个为0），合并后x与y的高度都不变
    else
    {
        f[y] = x;
        if(h[x] == h[y]) h[x]++;//这里树高相等，合并后父亲高度加1
    }
    sz[find(x)] = szx + szy;
}

int get_l(int pos, int diff, vector<int>& raw_diff, int n) {
    if (pos == 1) {
        return 0;
    } else if (raw_diff[pos-1] < diff) {
        return 0;
    } else {
        return sz[find(pos-1)];
    }
}

int get_r(int pos, int diff, vector<int>& raw_diff, int n) {
    if (pos == n) {
        return 0;
    } else if (raw_diff[pos+1] < diff) {
        return 0;
    } else {
        return sz[find(pos+1)];
    }
}
void solve() {
    int n;
    cin >> n;
    init(n + 20);
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<pair<int,int>> rank; 
    vector<int> diff(n+1);
    for (int i = 1; i <= n - 1; i++) {
        diff[i] = abs(v[i] - v[i+1]);
        rank.push_back({abs(v[i] - v[i+1]), -i});
    }
    sort(rank.begin(), rank.end());
    reverse(rank.begin(), rank.end());
    vector<int> ans(n+1, 0);
    int tot_at_this_stage = 0;
    int tot = 0;
    int last_diff = n;
    int progress = n - 1;
    for (const auto [vdiff, pos_rev]: rank) {
        if (last_diff == n) {
            last_diff = vdiff;
        }
        if (vdiff != last_diff) {
            tot += tot_at_this_stage;
            tot_at_this_stage = 0;
            for (int i = progress; i >= last_diff; i--) {
                ans[i] = tot;
            }
            progress = last_diff - 1;
            last_diff = vdiff;
        }
        const int pos = -pos_rev;
        const int lok = get_l(pos, vdiff, diff, n);
        const int rok = get_r(pos, vdiff, diff, n);
        if (lok > 0 && rok == 0) {
            tot_at_this_stage += (lok + 1);
            unite(pos-1, pos);
        }
        if (lok == 0 && rok > 0) {
            tot_at_this_stage += (rok + 1);
            unite(pos, pos + 1);
        }
        if (lok > 0 && rok > 0) {
            tot_at_this_stage += (lok * (rok + 1)) + (rok * (lok + 1));
            unite(pos, pos - 1);
            unite(pos, pos + 1);
        }
        if (!lok && !rok) {
            tot_at_this_stage += 1;
        }
    }
    for (int i = progress; i >= 1; i--) {
        ans[i] = tot;
    }
    for (int i = 1; i <=  n- 1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
}