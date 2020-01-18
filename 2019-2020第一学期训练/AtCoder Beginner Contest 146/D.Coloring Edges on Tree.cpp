#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],se=1,col[maxn],ans=0;
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa,int c){
	int w=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		w++;w+=(w==c);dfs(v,x,col[i/2]=w);
	}
	ans=max(ans,w);
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0,0);
	printf("%d\n",ans);
	for(int i=1;i<n;i++)printf("%d\n",col[i]);
	return 0;
}
