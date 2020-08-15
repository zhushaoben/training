#include<bits/stdc++.h>
using namespace std;
const int N=105,inf=0x3fffffff;
struct Edge{
	int next,to,fl;
}edge[N*20];
int n,m,fi[N],se,S,T,dis[N];
inline void add_edge(int u,int v,int fl=inf){edge[++se]={fi[u],v,fl},fi[u]=se;}
inline void add(int u,int v,int fl){add_edge(u,v,fl),add_edge(v,u,0);}
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
void init(){
	memset(fi,0,sizeof(int)*(n*2+5)),se=1,S=n*2+1,T=n*2+2;
}
void work(){
	int ans=0,sum=0,tmp,u,v,d;init();
	for(int i=1;i<=n;i++){
		scanf("%d",&d),sum+=d;
		add(S,i,d),add(i+n,T,d);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v),add(u,v+n,1),add(v,u+n,1);
	}
	while(bfs())
		while(tmp=dfs(S,inf))ans+=tmp;
	if(ans==sum)puts("Yes");
	else puts("No");
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
}
