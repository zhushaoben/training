#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct Edge{
	int next,to;
}edge[100];
LL f[51][1<<20];
int fi[51],se=1,fa[51],fa1[51],d[51],dep[51];
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x){
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x])continue;
		fa[v]=x,fa1[v]=i/2,dep[v]=dep[x]+1,dfs(v);
	}
}
int main(){
	int n,u,v,m,k,s;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1);scanf("%d",&m);s=1<<m;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		if(dep[u]>dep[v])swap(u,v);
		k=dep[v]-dep[u];
		for(int j=0;j<k;j++)d[fa1[v]]|=(1<<i),v=fa[v];
		while(v!=u)d[fa1[v]]|=1<<i,v=fa[v],d[fa1[u]]|=1<<i,u=fa[u];
	}
	f[1][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<s;j++){
			f[i+1][j]+=f[i][j];
			f[i+1][j|d[i]]+=f[i][j];
		}
	}
	printf("%lld",f[n][s-1]);
	return 0;
}
