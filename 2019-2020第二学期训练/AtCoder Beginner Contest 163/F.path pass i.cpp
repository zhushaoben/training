/*
求不经过任何颜色为i的节点的路径个数，最后用总路径数n*(n+1)/2减去它即可
显然，若将所有颜色为i的节点删除，会分离成若干CC
设它们的大小分别为s1,s2,....,sm，那么答案就是∑sj*(sj+1)/2
对于任意i，任意一个CC的深度最小的点要么没有父亲（等于根，令1为根），要么父亲颜色为i
又不难发现，任意一个非1节点，都只能作为一个i剖出来的CC的代表，
因为它们都有一个固定的父亲，也就有一个固定的父亲的颜色，
而节点1却可以作为任意一个i剖出来的CC的代表，需要特殊开数组处理。所以总CC数为O(n)
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
struct Edge{
	int next,to;
}edge[N*2];
int c[N],c1[N],fi[N],se,Size[N],Size1[N],n,Sizec[N];
LL ans[N];
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	int w=(c[x]!=c[fa]?c[fa]:0),fa1=c1[w];
	c1[w]=x;Size[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);Size[x]+=Size[v];
	}
	if(c[x]==c[fa])return;
	ans[w]-=1ll*(Size[x]-Size1[x])*(Size[x]-Size1[x]+1)/2;
	if(c1[c[x]])Size1[c1[c[x]]]+=Size[x];
	else Sizec[c[x]]+=Size[x];
	c1[w]=fa1;
}
int main(){
	int u,v;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	for(int i=1;i<=n;i++)Sizec[i]=n-Sizec[i],ans[i]+=1ll*n*(n+1)/2-1ll*Sizec[i]*(Sizec[i]+1)/2,printf("%lld\n",ans[i]);
	return 0;
} 
