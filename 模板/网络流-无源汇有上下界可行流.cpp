/******************************************************************
无源汇有上下界可行流
首先将有上下界的网络流图转化成普通的网络流图

先建立附加源点s(定为0)和附加汇点t(定为n+1) 
对于原图中的边x->y，若限制为[b,c]，那么连边x->y，流量为c-b
对于原图中的某一个点i，记flow(i)为流出这个点的所有边的下界和减去流入这个点的所有边的下界和
若flow(i)<0，那么连边s->i，流量为-flow(i)
若flow(i)>0，那么连边i->t，流量为flow(i)

求解方法

在新图上跑s到t的最大流 
若新图满流，那么一定存在一种可行流 
此时，原图中每一条边的流量应为新图中对应的边的流量+这条边的流量下界
******************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 205
#define maxm 50000
struct Edge{
	int next,to,w,fl;
}edge[maxm];
int n,m,t,fi[maxn],flow[maxn],ans[maxm],depth[maxn],que[maxn],first,last;
bool vis[maxn];
inline void add_edge(int u,int v,int w,int x){
	edge[x].next=fi[u],fi[u]=x,edge[x].to=v,edge[x].w=w,edge[x].fl=0,
	edge[x^1].next=fi[v],fi[v]=x^1,edge[x^1].to=u,edge[x^1].w=edge[x^1].fl=0;
} 
inline void init(){
	memset(fi,0,sizeof(fi)),memset(flow,0,sizeof(flow));
}
inline bool bfs(){//查找是否存在增广路 
	memset(vis,0,sizeof(vis));
	depth[0]=1,first=last=0,que[last++]=0,vis[0]=1;
	while(first<last){
		int x=que[first++],v;
		for(int i=fi[x];i;i=edge[i].next){
			v=edge[i].to;
			if(!vis[v]&&edge[i].w)que[last++]=v,vis[v]=1,depth[v]=depth[x]+1;//注：流量为0的边不能算 
		}
	}
	return vis[t];
}
int dfs(int u,int f){
	if(u==t||!f)return f;
	int v,x,sum=0;
	for(int i=fi[u];i;i=edge[i].next){
		v=edge[i].to;
		if(depth[v]==depth[u]+1){//增广路必须走向下一层 
			x=dfs(v,min(edge[i].w,f-sum));
			sum+=x,edge[i].w-=x,edge[i^1].w+=x,edge[i].fl+=x,edge[i^1].fl-=x;
		}
	}
	return sum;
}
inline int dinic(){//dinic求最大流 
	int sum=0,x;
	while(bfs()){//将图分层 
		if(x=dfs(0,0x3f3f3f3f))sum+=x;//在分过层的图上进行dfs求增广路 
	}
	return sum;
}
int main(){
	init(),scanf("%d%d",&n,&m),t=n+1;
	int u,v,w,se=(m<<1)+1,sum=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&u,&v,ans+i,&w),
		add_edge(u,v,w-ans[i],i<<1),flow[u]+=ans[i],flow[v]-=ans[i];
	}
	for(int i=1;i<=n;i++){
		if(flow[i]>0)add_edge(i,t,flow[i],++++se),sum+=flow[i];//若flow(i)>0，那么连边i->t，流量为flow(i)
		if(flow[i]<0)add_edge(0,i,-flow[i],++++se);//若flow(i)<0，那么连边s->i，流量为-flow(i)
	}
	if(dinic()==sum){//若新图满流，那么一定存在一种可行流  
		printf("YES\n");
		for(int i=1;i<=m;i++){
			printf("%d\n",ans[i]+edge[i<<1].fl);//每一条边的流量应为新图中对应的边的流量+这条边的流量下界
		}
	}
	else printf("NO\n");//否则，不存在可行流 
	return 0; 
}
