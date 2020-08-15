#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e5+5;
struct Edge{
	int next,to;
}edge[M];
int fi[N],se,vis[N],match[N],T;
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
bool dfs(int x){
	if(vis[x]==T)return 0;
	vis[x]=T;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!match[v]||dfs(match[v])){
			match[v]=x;return 1;
		}
	}
	return 0;
}
int main(){
	int n,n1,m,u,v;scanf("%d%d%d",&n,&n1,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add_edge(u,v+n);
	int ans=0;
	for(T=1;T<=n;T++)
		if(dfs(T))ans++;
	printf("%d",ans);
	return 0;
}
