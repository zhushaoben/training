#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
struct Edge{
	int next,to;
}edge[maxn*2+5];
int fi[maxn*2+5],se;
int que[maxn*2+5],s,t;
bool vis[maxn*2+5];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
	edge[++se].next=fi[v],edge[se].to=u,fi[v]=se;
}
void work(){
	int n,m,v,u;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fi[i]=fi[i+maxn]=0,vis[i]=0,vis[i+maxn]=0;
	se=0;
	for(int i=0;i<m;i++){scanf("%d%d",&u,&v);if(u!=v)add_edge(u,v+maxn);}
	s=t=0;
	que[t++]=1;vis[1]=1;
	while(s<t){
		int x=que[s++];
		for(int i=fi[x];i;i=edge[i].next){
			int v=edge[i].to;v-=maxn;
			if(!vis[v])vis[v]=1,que[t++]=v;
		}
	}
	if(t<n){
		printf("Yes\n%d %d\n",t,n-t);
		for(int i=1;i<=n;i++)if(vis[i])printf("%d ",i);puts("");
		for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",i);puts("");
		return;
	}
	s=t=0;que[t++]=maxn+1;vis[maxn+1]=1;
	while(s<t){
		int x=que[s++];
		for(int i=fi[x];i;i=edge[i].next){
			int v=edge[i].to;v+=maxn;
			if(!vis[v])vis[v]=1,que[t++]=v;
		}
	}
	if(t<n){
		printf("Yes\n%d %d\n",n-t,t);
		for(int i=1;i<=n;i++)if(!vis[i+maxn])printf("%d ",i);puts("");
		for(int i=1;i<=n;i++)if(vis[i+maxn])printf("%d ",i);puts("");
		return;
	}
	puts("No");
}
int main(){
//	freopen("1.in","r",stdin);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
