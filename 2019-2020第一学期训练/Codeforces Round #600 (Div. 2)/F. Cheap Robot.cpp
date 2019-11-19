#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
#define LL long long
#define P pair<LL,int>
struct Edge{
	int to,next,u;LL w;
	bool operator < (const Edge &b)const{return w<b.w;}
}edge[maxn*8+5];
int n,m,k,q,fi[maxn+5],se,head[maxn+5],S;LL dis[maxn+5];bool vis[maxn+5];
inline void add_edge(int u,int v,LL w,int fi[]){edge[++se].next=fi[u],edge[se].u=u,edge[se].to=v,edge[se].w=w,fi[u]=se;}
inline void add(int u,int v,LL w,int fi[]=fi){add_edge(u,v,w,fi),add_edge(v,u,w,fi);}
priority_queue<P >Q;
void dijk(){
	memset(dis,0x1f,sizeof(LL)*(n+5)),memset(vis,0,sizeof(bool)*(n+5));
	for(int i=1;i<=k;i++)Q.push(P{dis[i]=0,i});
	while(!Q.empty()){
		int u=Q.top().second,v;Q.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=fi[u];i;i=edge[i].next){
			v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].w)dis[v]=dis[u]+edge[i].w,Q.push(P{-dis[v],v});
		}
	}
}
int fa[maxn+5];
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int f[maxn+5][18],depth[maxn+5];LL ma[maxn+5][18];
void dfs(int x){
	for(int i=1;;i++){
		f[x][i]=f[f[x][i-1]][i-1],ma[x][i]=max(ma[x][i-1],ma[f[x][i-1]][i-1]);
		if(!f[x][i])break;
	}
	for(int i=head[x];i>S;i=edge[i].next){
		int v=edge[i].to;if(v==*f[x])continue;
		depth[v]=depth[x]+1,f[v][0]=x,ma[v][0]=edge[i].w,dfs(v);
	}
}
void up(int &x,int k){for(int i=17;~i;i--)if(k&(1<<i))x=f[x][i];}
int Lca(int u,int v){
	if(depth[u]>depth[v])swap(u,v);
	up(v,depth[v]-depth[u]);
	for(int i=17;~i;i--)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return u==v?u:f[u][0];
}
LL dist(int u,int v){
	int k=depth[u]-depth[v];LL ans=0;
	for(int i=17;~i;i--)if(k&(1<<i))ans=max(ans,ma[u][i]),u=f[u][i];
	return ans;
}
int main(){
	int u,v,w;scanf("%d%d%d%d",&n,&m,&k,&q);se=1;
	for(int i=0;i<m;i++)scanf("%d%d%d",&u,&v,&w),add(u,v,w);
	dijk();
	for(int i=1;i<=se;i++)edge[i].w+=dis[edge[i].to]+dis[edge[i].u];
	sort(edge+2,edge+se+1);S=se;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=2;i<=se;i++){
		u=Find(edge[i].u),v=Find(edge[i].to);
		if(u!=v)add(edge[i].u,edge[i].to,edge[i].w,head),fa[u]=v;
	}
	dfs(1);
	for(int i=0;i<q;i++){
		scanf("%d%d",&u,&v);
		int lca=Lca(u,v);
		printf("%lld\n",max(dist(u,lca),dist(v,lca)));
	}
	return 0;
}
