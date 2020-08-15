#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
typedef long long ll;
typedef double db;
const int N=1e6+5,M=1e6+5,mo=1e9+7;
const ll mnV=-1e17;
ll f[N],g[N],ans;
int w[N],v[N],Ref[N],W,V;
int i,n,T,sn,sm,m,l,j;
bool cmp(int x,int y)
{
    return w[x]<w[y];
}
int get(ll f[],int n)
{
    int s=0;
    fo(i,1,n) 
    {
        scanf("%d %d",w+i,v+i);
        Ref[i]=i;
        s+=w[i];
    }
    fo(i,0,s) f[i]=mnV;
    f[0]=0;
    s=0;
    sort(Ref+1,Ref+1+n,cmp);
    fo(l,1,n)
    {
        i=Ref[l];
        W=w[i];
        V=v[i];
        fd(j,s,0)
            if (f[j]!=mnV) 
                f[j+W]=max(f[j+W],f[j]+V);
        s+=w[i];
    }
    return s;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        sn=get(f,n);
        sm=get(g,m);
        sn=min(sn,sm);
        ans=0;
        fo(i,0,sn)
            ans=max(ans,f[i]+g[i]);
        printf("%lld\n",ans);
    }
}
