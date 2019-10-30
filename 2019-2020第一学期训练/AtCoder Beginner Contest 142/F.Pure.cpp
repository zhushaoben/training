#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
struct Edge{
	int next,to;
}edge[maxn*2+5];
int fi[maxn+5],se,pre[maxn+5],depth[maxn+5];
int vis[maxn+5],fl;
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;
}
int q[maxn+5],s,t;
void Put(int x){
	int ans=0,x1=x;fl=1;
	do{x1=pre[x1],ans++;}while(x1!=x);
	printf("%d\n",ans);
	x1=x;
	do{printf("%d\n",x),x=pre[x];}while(x!=x1);
}
int up(int x,int k){
	if(k<=0)return x;
	while(k--)x=pre[x];
	return x;
}
void bfs(int v1){
	s=t=0,q[t++]=v1,vis[v1]=v1,depth[v1]=1;
	while(s<t){
		int x=q[s++];
		for(int i=fi[x];i;i=edge[i].next){
			int v=edge[i].to;
			if(!vis[v])vis[v]=v1,q[t++]=v,pre[v]=x,depth[v]=depth[x]+1;
			else if(vis[v]==v1){
				if(up(x,depth[x]-depth[v])!=v)continue;
				pre[v]=x;
				if(depth[v]>depth[fl])fl=v;
			}
		}
		if(fl){Put(fl);return;}
	}
}
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	for(int s=1;s<=n;s++){
		if(!vis[s])bfs(s);
		if(fl)break;
	}
	if(!fl){puts("-1");return 0;}
	return 0;
}
