#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*21];
int fi[maxn+5],se,ans;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
bool vis[maxn+5];
void dfs(int x){
	vis[x]=1,ans++;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(!vis[v])dfs(v);
	}
}
int work(){
	LL k,w;
	int n,m,u,v,x;scanf("%d%d%lld",&n,&m,&k);
	memset(vis,0,sizeof(bool)*(n+5)),se=0,memset(fi,0,sizeof(int)*(n+5));
	while((~scanf("%d%d%lld",&u,&v,&w))&&(u|v|w))if(w<=k)add(u,v);
	ans=0;
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(!vis[x])dfs(x);
	}
	printf("%d\n",n-ans);
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
