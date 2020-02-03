#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],n1,se,si[maxn];LL num[maxn],ans,mi,mi1,si1,si2;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	si[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x),ans+=(num[v]+si[v])*si[x]+num[x]*si[v],si[x]+=si[v],num[x]+=num[v]+si[v];
	}
}
void dfs1(int x,int fa){
	if(fa)num[x]+=(num[fa]-num[x]-si[x])+(n1-si[x]);
	if(mi1)mi1=min(mi1,num[x]);
	else mi=min(mi,num[x]);
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs1(v,x);
	}
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=2;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0),n1=si1=si[1],mi=num[1],dfs1(1,0);
	for(int i=2;i<=n;i++)if(!si[i])dfs(i,0),n1=si2=si[i],mi1=1e18,dfs1(i,0);
	printf("%lld\n",ans+1ll*mi*si2+1ll*mi1*si1+1ll*si1*si2);
	return 0;
}
