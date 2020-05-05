#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=5005;
const ll mod=1e9+7;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
int n,m,s,a[N],f[N][N],g[N][N],cnt[N];
inline void chkmin(int &x,int y)
{
	if(x>y) x=y;
}
void solve()
{
	n=read(); m=read(); s=read();
	for(int i=1; i<=n; i++) a[i]=read();
	clr(f, 7); clr(g, 7); f[0][0]=g[0][0]=0;
	for(int i=1; i<=m; i++){
		int len=0; clr(cnt, 0);
		for(int j=i; j<=n; j+=m){
			int x=a[j]; cnt[x]++; len++;
		}
		for(int j=i; j<=n; j+=m){
			int x=a[j];
			for(int k=s; k>=0; k--){
				if(k>=x) chkmin(f[i][k], f[i-1][k-x]+len-cnt[x]);
				if(k>=x) chkmin(f[i][k], g[i-1][k]+len);
				chkmin(g[i][k], f[i][k]);
			}
		}
		for(int j=1; j<=s; j++) chkmin(g[i][j], g[i][j-1]);
	}
	printf("%d\n",f[m][s]);
}
int main()
{
	int T=1;
	while(T--) solve();
}
