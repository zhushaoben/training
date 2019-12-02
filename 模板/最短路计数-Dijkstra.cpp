/******************************************************************
最短路计数-dijkstra
在dijkstra更新距离时顺带更新最短路数量即可 
******************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 1000005
#define mo 100003
struct Edge{
	int next,to;
}edge[maxn*4];
int n,m,se,fi[maxn],dis[maxn],ans[maxn];
priority_queue<pair<int,int> >q;
bool vis[maxn];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
	edge[++se].next=fi[v],edge[se].to=u,fi[v]=se;
}
void init(){
	memset(dis,0x3f,sizeof(dis));
}
void Dijkstra(int s){//堆优化dijkstra求最短路 
	dis[s]=0,ans[s]=1;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]==dis[u]+1)(ans[v]+=ans[u])%=mo;//等于就累加 
			else if(dis[v]>dis[u]+1)dis[v]=dis[u]+1,q.push(make_pair(-dis[v],v)),ans[v]=ans[u];
		}
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v),add_edge(u,v);
	}
	Dijkstra(1);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}
