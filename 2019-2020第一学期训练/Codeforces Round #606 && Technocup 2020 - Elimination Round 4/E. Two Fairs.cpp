#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*5];
int fi[maxn],se,dfn[maxn],mi[maxn],si,a,b,size[maxn],siz[maxn];LL w,w1;
bool fl,d;
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	mi[x]=dfn[x]=++si;size[x]=siz[x]=1;
	if(x==a||x==b)d=1;
	int q=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		if(dfn[v]){mi[x]=min(mi[x],dfn[v]);continue;}
		else{
			dfs(v,x),mi[x]=min(mi[x],mi[v]),size[x]+=size[v],q++;
			if(mi[v]>=dfn[x])siz[x]+=size[v];
		} 
		if((x==a||x==b)&&!d){
			d=1;
			if(mi[v]>=dfn[x])fl=1,w=size[v];
		}
	}
	if(x==a||x==b){
		if(x==1&&q==1)dfn[x]=0;
		if(siz[x]==1)dfn[x]=0;
		d=0;
	}
}
void work(){
	int n,m,u,v;scanf("%d%d%d%d",&n,&m,&a,&b);
	fl=d=se=si=0,memset(dfn,0,sizeof(int)*(n+5));memset(fi,0,sizeof(int)*(n+5));
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	if(dfn[a]&&dfn[b]){
		w1=min(siz[a],siz[b]);
		if(!fl)w=max(siz[a],siz[b]);
		printf("%lld\n",fl?(n-w-1)*(w1-1):(w-1)*(w1-1));
	}
	else puts("0");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
