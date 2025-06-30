#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <array>

#define rgall(arr)          (arr).begin(),(arr).end()
#define rgo1(arr,cnt)       (arr).begin()+1,(arr).begin()+1+(cnt)
#define rgcnt(arr,cnt)      (arr).begin(),(arr).begin()+(cnt)
#define rgany(arr,rgl,rgr)  (arr).begin()+(rgl),(arr).begin()+(rgr)
#define fori(i,a,b)         for(int i=(a);i<=(b);i++)
#define ford(i,a,b)         for(int i=(a);i>=(b);i--)
#define fori0(i,a,b)        for(int i=(a);i<(b);i++)
#define ford0(i,a,b)        for(int i=(a);i>(b);i--)
#define fr first
#define sc second

using namespace std;

vector<pair<int,int>> ans;
array<int,101> va,vb;

inline void f(int i,int j)
{
    if(i>=j)
        cerr<<"ArC";
    ans.emplace_back(i,j);
    swap(va[i],va[j]),--va[i],++va[j];
}

int main(int argc,char* argv[],char* envp[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // fori(i,1,50)
    //     cout<<"1 ";
    // fori(i,1,50)
    //     cout<<"100 ";
    // cout<<endl;
    // fori(i,1,50)
    //     cout<<"50 ";
    // fori(i,1,50)
    //     cout<<"51 ";
    // return 0;
    int cnt,sum=0;
    cin>>cnt;
    fori(i,1,cnt)
        cin>>va[i],sum+=va[i];
    fori(i,1,cnt)
        cin>>vb[i],sum-=vb[i];
    if(sum)
        return cout<<"No",0;
    if(cnt==2)
    {
        if(va[1]==vb[1])
            return cout<<"Yes\n0",0;
        if(va[1]+1==vb[2])
            return cout<<"Yes\n1\n1 2",0;
        return cout<<"No",0;
    }
    cout<<"Yes\n";
    fori(i,1,cnt-2)
    {
        int k=i;
        fori(j,i,cnt)
            if(abs(va[j]-vb[i])<abs(va[k]-vb[i]))
                k=j;
        if(k!=i)
            f(i,k);
        while(va[i]<vb[i])
            f(i,i+1),f(i+1,i+2),f(i,i+2);
        while(va[i]>vb[i])
            f(i,i+2),f(i+1,i+2),f(i,i+1);
    }
    while(va[cnt-1]<vb[cnt-1])
        f(cnt-1,cnt),f(cnt-2,cnt),f(cnt-2,cnt-1),f(cnt-2,cnt);
    while(va[cnt-1]>vb[cnt-1])
        f(cnt-2,cnt),f(cnt-2,cnt-1),f(cnt-2,cnt),f(cnt-1,cnt);
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i.fr<<' '<<i.sc<<'\n';
    fori(i,1,cnt)
        cerr<<va[i]-vb[i];
    return 0;
}
/*
x,a,b
x,b-1,a+1
a,b-1,x+1
b-2,a+1,x+1
x,a+1,b-1
*/