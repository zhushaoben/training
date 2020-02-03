#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],se,f[maxn][3],ans[maxn][3][3],size[maxn];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	ans[x][0][0]=x;size[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);
		if(size[v]>=3&&f[v][2]>f[x][2])f[x][2]=f[v][2],ans[x][2][0]=ans[v][2][0],ans[x][2][1]=ans[v][2][1],ans[x][2][2]=ans[v][2][2];
		if(size[x]>=2&&f[v][0]+f[x][1]+1>f[x][2])f[x][2]=f[v][0]+1+f[x][1],ans[x][2][0]=ans[v][0][0],ans[x][2][1]=ans[x][1][0],ans[x][2][2]=ans[x][1][1];
		if(size[v]>=2&&f[v][1]+1+f[x][0]>f[x][2])f[x][2]=f[v][1]+1+f[x][0],ans[x][2][0]=ans[x][0][0],ans[x][2][1]=ans[v][1][0],ans[x][2][2]=ans[v][1][1];
		if(f[v][0]+1+f[x][0]>f[x][1])f[x][1]=f[v][0]+1+f[x][0],ans[x][1][0]=ans[v][0][0],ans[x][1][1]=ans[x][0][0];
		if(size[v]>=2&&f[v][1]+1>f[x][1])f[x][1]=f[v][1]+1,ans[x][1][0]=ans[v][1][0],ans[x][1][1]=ans[v][1][1];
		if(f[v][0]+1>f[x][0])f[x][0]=f[v][0]+1,ans[x][0][0]=ans[v][0][0];
		size[x]+=size[v];
	}
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	printf("%d\n%d %d %d\n",f[1][2],ans[1][2][0],ans[1][2][1],ans[1][2][2]);
	return 0;
}
/*
3
1 2
2 3
*/
