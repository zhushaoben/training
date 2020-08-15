#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,d[N],dfn[N],si;
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	if(d[x]==1)dfn[si++]=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,x);
	}
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v),d[u]++,d[v]++;
	}
	dfs(1,0);
	printf("%d\n",(si+1)/2);
	for(int i=0;i<(si+1)/2;i++){
		printf("%d %d\n",dfn[i],dfn[min(si-1,i+(si+1)/2)]);
	}
	return 0;
}
