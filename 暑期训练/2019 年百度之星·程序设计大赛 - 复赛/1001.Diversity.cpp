#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2];
int l[maxn],r[maxn],fi[maxn],se;
LL dp[maxn][2];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,
	edge[++se].next=fi[v],fi[v]=se,edge[se].to=u;
}
void dfs(int x,int fa){
	dp[x][0]=dp[x][1]=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,x);
		dp[x][0]+=max(abs(l[x]-l[v])+dp[v][0],abs(l[x]-r[v])+dp[v][1]);
		dp[x][1]+=max(abs(r[x]-l[v])+dp[v][0],abs(r[x]-r[v])+dp[v][1]);
	}
}
void work(){
	memset(fi,0,sizeof(fi)),se=0;
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	for(int i=1;i<=n;i++)scanf("%d%d",l+i,r+i);
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
