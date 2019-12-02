#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 105
#define maxe 20005
int n,low[maxn][maxn],high[maxn][maxn],fi[maxn],se=1,ans,s,t,que[maxn],first,last,flow[maxn],depth[maxn];
struct Edge{
	int next,to,fl,w;
}edge[maxe];
inline void add_edge(int u,int v,int w1,int w2){
	edge[++se].next=fi[u],edge[se].fl=0,edge[se].to=v,edge[se].w=w1,fi[u]=se,
	edge[++se].next=fi[v],edge[se].fl=0,edge[se].to=u,edge[se].w=w2,fi[v]=se;
}
int dfs(int x,int fl){
	if(x==t||!fl)return fl;
	int tmp=0,t;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(depth[v]==depth[x]+1){
			t=dfs(v,min(fl-tmp,edge[i].w));
			edge[i].w-=t,edge[i].fl+=t,edge[i^1].w+=t,edge[i^1].fl-=t,tmp+=t;
		}
	}
	return tmp;
}
inline bool bfs(){
	first=last=0,memset(depth,0,sizeof(depth)),que[last++]=s,depth[s]=1;
	while(first<last){
		int x=que[first++];
		for(int i=fi[x];i;i=edge[i].next){
			int v=edge[i].to;
			if(depth[v]||!edge[i].w)continue;
			depth[v]=depth[x]+1,que[last++]=v;
		}
	}
	return depth[t]?1:0;
}
inline void dinic(){//最大流 
	int x;
	while(bfs()){
		while(x=dfs(s,0x3f3f3f3f))ans+=x;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d%d",&low[i][j],&high[i][j]);//读入上下界 
			flow[i]+=low[i][j],flow[j]-=low[i][j];
		}
	}
	high[n][1]=0x3f3f3f3f;//在原图中添加一条边t->s，流量限制为[0,inf] 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			add_edge(i,j,high[i][j]-low[i][j],high[j][i]-low[j][i]);
		}
	}
	s=0,t=n+1;
	for(int i=1;i<=n;i++){
		if(flow[i]>0)add_edge(i,t,flow[i],0);
		if(flow[i]<0)add_edge(s,i,-flow[i],0);
	}
	dinic();//对ss到tt求一遍最大流 
	#if 1//删去t->s这条边，统计∑f(s,i) 
	ans=0,edge[(n-1)<<1].w=high[1][n]-low[1][n];
	for(int i=fi[n];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=1)ans-=edge[i].fl;
	}
	s=1,t=n;
	#endif
	#if 0//或者不删去t->s这条边,这时t->s这条边的反向边s->t流量为∑f(s,i) 
	s=1,t=n,ans=0;
	#endif
	dinic();//在残存网络中跑一遍s到t的最大流 
	printf("%d",ans);
	return 0;
} 
