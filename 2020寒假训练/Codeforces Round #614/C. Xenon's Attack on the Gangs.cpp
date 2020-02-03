#include<bits/stdc++.h>
using namespace std;
#define maxn 3005
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],se,s,fa[maxn][maxn],si[maxn][maxn];LL f[maxn][maxn];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x){
	si[x][s]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x][s])continue;
		fa[v][s]=x;dfs(v);si[x][s]+=si[v][s];
	}
}
LL dp(int u,int v){
	if(f[u][v])return f[u][v];
	if(u==v)return 0;
	return f[u][v]=max(dp(u,fa[v][u]),dp(fa[u][v],v))+si[u][v]*si[v][u];
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	for(s=1;s<=n;s++)dfs(s);
	LL ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)ans=max(ans,dp(i,j));
	}
	printf("%lld",ans);
	return 0;
} 
