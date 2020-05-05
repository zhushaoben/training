#include<bits/stdc++.h>
using namespace std;
#define maxn 105
struct Edge{
	int next,to;
}edge[maxn*maxn],edge1[maxn*maxn];
int fi[maxn],fi1[maxn],s[maxn],s1[maxn],vis[maxn],now,fl,se,w[maxn][maxn];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
	edge1[se].next=fi1[v],edge1[se].to=u,fi1[v]=se;
}
void dfs(int x){
	if(vis[x]==-1){fl=0;return;}
	vis[x]=-1;
	if(x!=now){
		if(w[x][now]){fl=0;return;}
		w[now][x]=1;s[now]++;
	}
	for(int i=fi[x];i;i=edge[i].next){
		dfs(edge[i].to);
	}
	vis[x]=0;
}
void dfs1(int x){
	if(vis[x]==-1){fl=0;return;}
	vis[x]=-1;
	if(x!=now){
		if(w[now][x]){fl=0;return;}
		w[x][now]=1;s1[now]++;
	}
	for(int i=fi1[x];i;i=edge1[i].next){
		dfs1(edge1[i].to);
	}
	vis[x]=0;
}
void work(){
	int n,m,u,v;scanf("%d%d",&n,&m);se=0;
	for(int i=1;i<=n;i++){
		vis[i]=fi[i]=fi1[i]=s[i]=s1[i]=0;
		for(int j=1;j<=n;j++)w[i][j]=0;
	}
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	fl=1;for(int i=1;i<=n;i++)now=i,dfs(i);
	for(int i=1;i<=n;i++)now=i,dfs1(i);
	if(!fl)for(int i=0;i<n;i++)putchar('0');
	else for(int i=1;i<=n;i++)putchar((s[i]>n/2||s1[i]>n/2)?'0':'1');
	putchar(' ');
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
