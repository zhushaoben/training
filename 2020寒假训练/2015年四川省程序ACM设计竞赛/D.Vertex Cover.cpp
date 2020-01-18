#include <bits/stdc++.h>
using namespace std;
#define maxn 505
struct Edge{
	int next,to;
}edge[maxn*50];
int n,m,fi[maxn],num[maxn],G[maxn],S[maxn],se,ans;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
bool g[maxn],g1[maxn];
int now,mi;
inline int si(int x){
	int ans=0;while(x&1)x>>=1,ans++;
	return ans;
}
void dfs(int d,int G1){
	if(now>=ans)return;
	if(d==mi+1){ans=min(ans,now);return;}
	if((G1&(1<<d))){dfs(d+1,G1);return;}
	now++,dfs(d+1,G1|(1<<d)),now--;
	if(num[d]>=ans)return;
	for(int i=fi[d];i;i=edge[i].next){
		int v=edge[i].to;
		g1[v]=g[v]^1,g[v]=1;
		if(g1[v])now++;
	}
	int w=si(S[d]^(S[d]&G1));
	now+=w,dfs(d+1,G1|G[d]),now-=w;
	for(int i=fi[d];i;i=edge[i].next){
		int v=edge[i].to;
		g[v]^=g1[v];if(g1[v])now--;
	}
}
void work(){
	int u,v;ans=mi=min(30,n);se=now=0;
	memset(fi,0,sizeof(fi)),memset(G,0,sizeof(G)),memset(num,0,sizeof(num)),memset(S,0,sizeof(S));
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);num[u]++;
		if(v>30)add_edge(u,v);
		else num[v]++,G[u]|=(1<<v),G[v]|=(1<<u),S[u]|=(1<<v);
	}
	dfs(1,0);
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
}
