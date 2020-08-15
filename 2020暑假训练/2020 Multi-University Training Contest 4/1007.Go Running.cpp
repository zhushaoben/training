#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3fffffff;
int t1[N],x[N],a[N],b[N],sia,sib;
struct Edge{
	int next,to,fl;
}edge[N*10];
int n,m,fi[N*2],se,S,T,dis[N*2];
inline void add_edge(int u,int v,int fl=inf){edge[++se]={fi[u],v,fl},fi[u]=se;}
inline void add(int u,int v,int fl){add_edge(u,v,fl),add_edge(v,u,0);}
void init(int n){memset(fi,0,sizeof(int)*(n+5)),se=1,S=n+1,T=n+2;}
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
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",t1+i,x+i);
		a[i]=t1[i]-x[i];b[i]=t1[i]-1e9+x[i];
	}
	sort(a,a+n),sia=unique(a,a+n)-a;
	sort(b,b+n),sib=unique(b,b+n)-b;
	init(sia+sib);
	for(int i=1;i<=sia;i++)add(S,i,1);
	for(int i=1;i<=sib;i++)add(i+sia,T,1);
	for(int i=0;i<n;i++){
		int x1=lower_bound(a,a+sia,t1[i]-x[i])-a+1,y=lower_bound(b,b+sib,t1[i]-1e9+x[i])-b+1;
		add(x1,y+sia,1);
	}
	int ans=0,tmp;
	while(bfs())
		while(tmp=dfs(S,inf))ans+=tmp;
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
