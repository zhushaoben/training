#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],n,se,ans=0,que[maxn],s,t,dep[maxn],U,V,dep1[maxn];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void bfs(){
	dep[U]=1,que[t++]=U;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!dep[v])dep[v]=dep[u]+1,que[t++]=v;
		}
	}
	s=t=1;que[t++]=V,dep1[V]=1;
	while(s<t){
		int u=que[s++];
		if(dep[u]<dep1[u])ans=max(ans,dep1[u]-1);
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!dep1[v])dep1[v]=dep1[u]+1,que[t++]=v;
		}
	}
}
int main(){
	int u,v;scanf("%d%d%d",&n,&U,&V);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	bfs();
	printf("%d",ans-1);
	return 0;
}
