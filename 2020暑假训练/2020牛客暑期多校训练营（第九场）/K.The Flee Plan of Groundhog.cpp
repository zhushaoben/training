#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,fa[N],depth[N],depth1[N];
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs1(int x){
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x])continue;
		depth[v]=depth[x]+1,fa[v]=x;dfs1(v);
	}
}
int ans=0;
void dfs(int x,int f){
	ans=max(ans,(depth[x]-1)/2+1);
	if(depth1[x]*2>=depth[x]){return;}
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==f)continue;
		depth1[v]=depth1[x]+1;dfs(v,x);
	}
}
int main(){
	int n,t,u,v,x=1;scanf("%d%d",&n,&t);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs1(n);fa[n]=n;
	for(int i=0;i<t;i++)x=fa[x];
	if(x!=n)dfs(x,0);
	printf("%d\n",ans);
	return 0;
}
/*
7 3
1 2
2 5
5 7
5 6
3 6
3 4
*/
