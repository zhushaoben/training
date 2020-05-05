#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge{
	int next,to;
}edge[N*4];
int fi[N],se,depth[N],fa[N],S;
bool vis[N];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x){
	int w=0,mi=depth[x],mi1=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(depth[v]){
			if(depth[v]<mi)mi=depth[v],mi1=v;
			continue;
		}
		w++;fa[v]=x,depth[v]=depth[x]+1;dfs(v);
	}
	if(depth[x]-mi+1>=S){
		printf("2\n%d\n%d ",depth[x]-mi+1,x);
		while(x!=mi1)x=fa[x],printf("%d ",x);
		exit(0);
	}
	if(!w||!vis[x])for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		vis[v]=1;
	}
}
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);S=ceil(sqrt(n));
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v);
	depth[1]=1;dfs(1);
	puts("1");
	int num=0;
	for(int i=1;i<=n;i++){
		if(!vis[i])printf("%d ",i),num++;
		if(num==S)break;
	}
	return 0;
}
