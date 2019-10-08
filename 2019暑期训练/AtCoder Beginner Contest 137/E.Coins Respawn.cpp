#include<bits/stdc++.h>
using namespace std;
#define maxn 2500
#define maxm 5000
#define LL long long
#define inf 1e15
struct Edge{
	int next,to,w;
}edge[maxm+5],edge1[maxm+5];
int fi[maxn+5],se,n,fi1[maxn+5];
inline void add_edge(int u,int v,int w){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,edge[se].w=w;
	edge1[se].next=fi1[v],fi1[v]=se,edge1[se].to=u;
}
queue<int>q;
bool vis[maxn+5],vis1[maxn+5];int num[maxn+5];LL dis[maxn+5];
bool spfa(){
	q.push(1),vis[1]=1,num[1]=1;
	for(int i=2;i<=n;i++)dis[i]=inf;
	while(!q.empty()){
		int u=q.front();q.pop();vis[u]=0;
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!vis1[v])continue;
			if(edge[i].w+dis[u]<dis[v]){
				dis[v]=edge[i].w+dis[u];
				if(!vis[v])vis[v]=1,q.push(v),num[v]++;
				if(num[v]>=n)return 0;
			}
		} 
	}
	return 1;
}
void dfs(int x){
	vis1[x]=1;
	for(int i=fi1[x];i;i=edge1[i].next){
		int v=edge1[i].to;
		if(vis1[v])continue;
		dfs(v);
	}
}
int main(){
	int m,p,u,v,w;scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<m;i++)scanf("%d%d%d",&u,&v,&w),add_edge(u,v,p-w);
	dfs(n);
	if(spfa())printf("%lld\n",max(0ll,-dis[n]));
	else puts("-1");
	return 0;
}
