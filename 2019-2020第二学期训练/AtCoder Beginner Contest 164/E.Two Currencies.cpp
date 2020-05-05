#include<bits/stdc++.h>
using namespace std;
const int N=55;
struct Edge{
	int next,to,w,v;
}edge[N<<2];
struct Node{
	long long val;int u,s;
	bool operator < (const Node &b)const{return val>b.val;}
}u;
int fi[N],se,s,s1,c[N],d[N];long long dis[N][N*N];
bool vis[N][N*N];
inline void add_edge(int u,int v,int a,int b){edge[++se]={fi[u],v,a,b},fi[u]=se;}
inline void add(int u,int v,int a,int b){add_edge(u,v,a,b),add_edge(v,u,a,b);}
priority_queue<Node>q;
void dijk(){
	memset(dis,0x1f,sizeof(dis));dis[1][s]=0;
	q.push(Node{0,1,s});
	while(!q.empty()){
		u=q.top();q.pop();
		if(vis[u.u][u.s])continue;
		vis[u.u][u.s]=1;
		if(dis[u.u][min(s1,u.s+c[u.u])]>dis[u.u][u.s]+d[u.u]){
			dis[u.u][min(s1,u.s+c[u.u])]=dis[u.u][u.s]+d[u.u];
			q.push(Node{dis[u.u][min(s1,u.s+c[u.u])],u.u,min(s1,u.s+c[u.u])});
		}
		for(int i=fi[u.u];i;i=edge[i].next){
			int v=edge[i].to;
			if(u.s>=edge[i].w&&dis[v][u.s-edge[i].w]>dis[u.u][u.s]+edge[i].v){
				dis[v][u.s-edge[i].w]=dis[u.u][u.s]+edge[i].v;
				q.push(Node{dis[v][u.s-edge[i].w],v,u.s-edge[i].w});
			}
		}
	} 
}
int main(){
	int n,m,u,v,a,b;scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++)scanf("%d%d%d%d",&u,&v,&a,&b),add(u,v,a,b),s1=max(s1,a);
	for(int i=1;i<=n;i++)scanf("%d%d",c+i,d+i);
	s=min(s,s1*=n);
	dijk();
	for(int i=2;i<=n;i++){
		long long ans=0x1f1f1f1f1f1f1f1f;
		for(int j=0;j<=s1;j++)ans=min(ans,dis[i][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
