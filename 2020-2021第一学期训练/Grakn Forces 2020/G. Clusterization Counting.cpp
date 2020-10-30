#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5,mo=998244353;
struct DSU{
	int dsu[N],si[N],w[N];
	void init(int n){for(int i=1;i<=n;i++)dsu[i]=i,si[i]=1;}
	int Find(int x){return dsu[x]==x?x:dsu[x]=Find(dsu[x]);}
	void merge(int a,int b){dsu[b]=a,si[a]+=si[b],w[a]+=w[b];}
}S;
struct Edge{
	int u,v,w;
	bool operator < (const Edge &b)const{return w<b.w;}
}a[N*N];
int dp[N][N],n,l[N],r[N];
void dfs(int x){
	if(x<=n){dp[x][1]=1;return;}
	int u,v;dfs(u=l[x]),dfs(v=r[x]);
	for(int i=1;i<=S.si[u];i++)
		for(int j=1;j<=S.si[v];j++)
			dp[x][i+j]=(dp[x][i+j]+1ll*dp[u][i]*dp[v][j])%mo;
}
int main(){
	int x,si=0;scanf("%d",&n);
	S.init(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			if(i<j)a[si++]={i,j,x};
		}
	}
	sort(a,a+si);
	int cur=n;
	for(int i=0;i<si;i++){
		int u=S.Find(a[i].u),v=S.Find(a[i].v);
		if(u!=v){
			S.dsu[++cur]=cur,S.merge(cur,u),S.merge(cur,v);
			l[cur]=u,r[cur]=v,u=cur;
		}
		S.w[u]++;
		if(S.w[u]==S.si[u]*(S.si[u]-1)/2)dp[u][1]=1;
	}
	dfs(cur);
	for(int i=1;i<=n;i++)printf("%d ",dp[cur][i]);
	return 0;
}
