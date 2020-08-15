#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,inf=0x3fffffff;
struct Edge{
	int next,to,fl;
}edge[N*30];
int n,m,w[N],type[N],fi[N],se,S,T,dis[N];
bool vis[N];
inline void add_edge(int u,int v,int fl=inf){edge[++se]={fi[u],v,fl},fi[u]=se;}
inline void add(int u,int v,int fl){add_edge(u,v,fl),add_edge(v,u,0);}
void init(){memset(fi,0,sizeof(int)*(2*n+5)),memset(vis,0,sizeof(bool)*(2*n+5)),se=1,vis[S=2*n+1]=vis[T=2*n+2]=1;}
void build(int x,int d){
	if(vis[x])return;
	vis[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		build(edge[i].to,!d);
		if(!d)edge[i].fl=0;
	}
	if(d)add(S,x,w[x]);
	else add(x,T,w[x]);
}
int que[N],s,t;
bool bfs(){
	memset(dis,-1,sizeof(int)*(T+1));
	s=t=0;que[t++]=S,dis[S]=0;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].fl&&dis[v]==-1){
				dis[v]=dis[u]+1;
				que[t++]=v;
			}
		}
	}
	return dis[T]!=-1;
}
int dfs(int x,int low){
	int tmp=low,w;
	if(x==T)return low;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(dis[v]==dis[x]+1&&edge[i].fl){
			w=dfs(v,min(tmp,edge[i].fl));
			edge[i].fl-=w,edge[i^1].fl+=w,tmp-=w;
		}
	}
	return low-tmp;
}
void work(){
	int a,b,ans=0,tmp;init();
	for(int i=1;i<=n;i++)scanf("%d",w+i),w[i+n]=w[i];
	for(int i=1;i<=n;i++){
		scanf("%d",type+i);
		if(type[i]==3)ans-=w[i],add_edge(i,i+n),add_edge(i+n,i);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(!(type[a]&type[b]))continue;
		if((type[a]&type[b])==2&&(type[a]|type[b])==3)
			if(type[b]==3)add_edge(a,b+n),add_edge(b+n,a);
			else add_edge(a+n,b),add_edge(b,a+n);
		else add_edge(a,b),add_edge(b,a);
		if((type[a]&type[b])==3)add_edge(a+n,b+n),add_edge(b+n,a+n);
	}
	for(int i=1;i<=n;i++)build(i,1);
	while(bfs())
		while(tmp=dfs(S,inf))ans+=tmp;
	printf("%d\n",ans);
	
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
}
