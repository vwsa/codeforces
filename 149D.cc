#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N = 750;
typedef long long lld;
const int Mod=1000000007;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,l,r) for(int i=l;i<=r;i++)

char st[N];
int n,match[N],stack[N];
lld opt[N][N][5][5];

bool Check(int l,int r){
    if(l==0||r==0||l!=r) return true;
    return false;
}

lld dp(int l,int r,int c1,int c2){
    if(opt[l][r][c1][c2]+1!=0) return opt[l][r][c1][c2];
    lld ans=0;
    if(match[l]==r){
        if((c1==0||c2==0)&&(c1+c2)){
            if(l+1==r) return opt[l][r][c1][c2]=1;
            Rep(left,0,2)
                Rep(right,0,2)
                    if(Check(c1,left)&&Check(right,c2))
                        ans=(ans+dp(l+1,r-1,left,right))%Mod;
        }
        else return opt[l][r][c1][c2]=0;
    }
    else{
        Rep(left,0,2)
          Rep(right,0,2)
            if(Check(left,right))
                ans=(ans+dp(l,match[l],c1,left)*dp(match[l]+1,r,right,c2))%Mod;
    }
    return opt[l][r][c1][c2]=ans%Mod;
}

void init(){
    memset(opt,-1,sizeof(opt));
    scanf("%s",st+1);
    n=strlen(st+1);
    For(i,n)
      if(st[i]=='(') stack[++stack[0]]=i;
      else           match[stack[stack[0]--]]=i;
}

int main(){
    init();lld ans=0;
    Rep(i,0,2)
      Rep(j,0,2)
        ans=(ans+dp(1,n,i,j))%Mod;
    printf("%d\n",ans%Mod);
    return 0;
}