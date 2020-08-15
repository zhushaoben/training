#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct Edge{
	int next,to;
}edge[N*20];
int col[N],fi[N],se,fl;
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
int n,m,x,y,u,v;
void dfs(int x,int d){
	if(col[x]>0){fl|=(col[x]!=d);return;}
	col[x]=d;
	for(int i=fi[x];i;i=edge[i].next)dfs(edge[i].to,d^3);
}
void work(){
	memset(fi,0,sizeof(int)*(n+1)),memset(col,-1,sizeof(int)*(n+1)),se=fl=0;
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v),col[u]=col[v]=0;
	for(int i=0;i<x;i++)scanf("%d",&u),dfs(u,1);
	for(int i=0;i<y;i++)scanf("%d",&u),dfs(u,2);
	for(int i=1;i<=n;i++)
		if(!col[i])dfs(i,1);
		else fl|=col[i]==-1;
	printf("%s\n",fl?"NO":"YES");
}
int main(){
	while(~scanf("%d%d%d%d",&n,&m,&x,&y))work();
	return 0;
} 
