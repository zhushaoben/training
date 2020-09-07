#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,ma,a1[N],a2[N],dis[N];
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
void dfs(int x,int fa){
	a1[x]=a2[x]=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);
		if(a1[v]+1>a1[x])a2[x]=a1[x],a1[x]=a1[v]+1;
		else if(a1[v]+1>a2[x])a2[x]=a1[v]+1;
	}
	ma=max(a1[x]+a2[x],ma);
}
void dfs1(int x,int fa){
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dis[v]=dis[x]+1,dfs1(v,x);
	}
}
int n,a,b,da,db;
void work(){
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	memset(fi,0,sizeof(int)*(n+2));
	int u,v;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
	dis[a]=0;dfs1(a,0);
	ma=0;dfs(1,0);
	if(da*2>=min(db,ma)||dis[b]<=da)puts("Alice");
	else puts("Bob");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
