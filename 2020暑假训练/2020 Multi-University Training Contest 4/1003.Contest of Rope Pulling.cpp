#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=1005,M=1000003;
const ll inf=0xdfdfdfdfdfdfdfdf;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
struct Node{
	int w,v;
	bool operator <(const Node &b)const{
		return v>b.v;
	}
}a[N],b[N];
ll f[M],f1[M+N],f2[M];
int que[M],s,t;
inline void chkmax(ll &x, ll y){if(x<y) x=y;}
void solve()
{
	int n=read(),m=read(),sum=0,sum1=0;
	for(int i=0; i<n; i++) sum+=(a[i].w=read()),a[i].v=read();
	for(int i=0; i<m; i++) sum1+=(b[i].w=read()),b[i].v=read();
	memset(f, 0xdf, sizeof(ll)*(sum+2));
	memset(f1,0xdf, sizeof(ll)*(sum1+2));f[0]=f1[0]=0;
	sort(a,a+n),sort(b,b+m);
	int s=0,n1=max(min(n,100),n-n/15),m1=max(min(m,100),m-m/15);
	for(int i=0;i<n1;i++){
		register ll w=a[i].v;
    	for(register int j=s,y=s+a[i].w;j>=0;y--,j--)
     	    f[y]=max(f[y],f[j]+w);
    	s+=a[i].w;
 	}
	s=0;
	for(int i=0;i<m1;i++){
		register ll w=b[i].v;
    	for(register int j=s,y=s+b[i].w;j>=0;y--,j--)
            f1[y]=max(f1[y],f1[j]+w);
        s+=b[i].w;
    }
	ll ans=0;
	for(int i=1;i<=sum;i++)ans=max(ans,f[i]+f1[i]);
	printf("%lld\n",ans);
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int T=read();
	while(T--) solve();
}
