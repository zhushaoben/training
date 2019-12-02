#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],se,l[maxn],r[maxn],d[maxn];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
LL sum[maxn*4],sum1[maxn*4],lazy[maxn*4],ans,pro;
int L,R,w;
inline void pushdown(int x,int s1,int s2){if(lazy[x])sum[x<<1]+=lazy[x]*s1,sum[x<<1|1]+=lazy[x]*s2,lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],lazy[x]=0;}
inline void update(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
void modify(int l,int r,int x){
	if(L<=l&&R>=r){int s=r-l+1;sum[x]+=w*s,lazy[x]+=w;return;}
	int mid=(l+r)>>1;pushdown(x,mid-l+1,r-mid);
	if(L<=mid)modify(l,mid,x<<1);
	if(R>mid)modify(mid+1,r,x<<1|1);
	update(x);
}
void modify1(int l,int r,int x){
	if(L<=l&&R>=r){int s=r-l+1;sum[x]+=w*s,lazy[x]+=w;}
	int mid=(l+r)>>1;pushdown(x,mid-l+1,r-mid);
	if(L<=mid)modify1(l,mid,x<<1);
	if(R>mid)modify1(mid+1,r,x<<1|1);
	update(x);
}
void build(int l,int r,int x){
	sum1[x]=sum[x];
	if(l==r)return;
	int mid=(l+r)>>1;pushdown(x,mid-l+1,r-mid);
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
}
void dfs(int x,int fa){
	ans+=pro;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		
	}
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",l+i,r+i),L=l[i],R=r[i],modify1(1,n,1);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),scanf("%d%d",&u,&v),d[u]++,d[v]++;
	build(1,n,1);
	for(int i=1;i<=n;i++)if(d[i]==1)u=i;
	dfs(u,0);
	return 0;
}
