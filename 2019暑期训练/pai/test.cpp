#include<bits/stdc++.h>
using namespace std;
#define maxn 2500
#define maxm 5000
struct Edge{
	int next,to,w;
}edge[maxm+5];
int fi[maxn+5],se,n;
inline void add_edge(int u,int v,int w){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,edge[se].w=w;
}
queue<int>q;
bool vis[maxn+5];int num[maxn+5],dis[maxn+5];
bool spfa(){
	q.push(1),vis[1]=1,num[1]=1;
	while(!q.empty()){
		int u=q.front();q.pop();vis[u]=0;
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].w+dis[u]<dis[v]){
				dis[v]=edge[i].w+dis[u];
				if(!vis[v])vis[v]=1,q.push(v),num[v]++;
				if(num[v]>=n)return 0;
			}
		} 
	}
	return 1;
}
int main(){
	int m,p,u,v,w;scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<m;i++)scanf("%d%d%d",&u,&v,&w),add_edge(u,v,p-w);
	if(spfa())printf("%d\n",-dis[n]);
	else puts("-1");
	return 0;
}
