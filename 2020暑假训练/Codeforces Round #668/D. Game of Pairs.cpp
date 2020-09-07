#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,vis[N],st[2][N];
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int d){
	vis[x]=1,st[d][++st[d][0]]=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(vis[v])continue;
		dfs(v,d^1);
	}
}
int main(){
	int n,x;scanf("%d",&n);
	if(n%2){
		puts("Second");fflush(stdout);
		for(int i=1;i<=(n<<1);i++){
			scanf("%d",&x);
			if(vis[x])add(vis[x],i);
			else vis[x]=i;
		}
		for(int i=1;i<=n;i++)add(i,i+n);
		memset(vis,0,sizeof(int)*(n+5));
		for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
		long long sum=0;
		for(int i=1;i<=n;i++)sum+=st[0][i];
		if(sum%(n<<1))for(int i=1;i<=n;i++)printf("%d ",st[1][i]);
		else for(int i=1;i<=n;i++)printf("%d ",st[0][i]);
	}
	else{
		puts("First");
		for(int i=0;i<(n<<1);i++)printf("%d ",i%n+1);
	}
	fflush(stdout);
	return 0;
}
