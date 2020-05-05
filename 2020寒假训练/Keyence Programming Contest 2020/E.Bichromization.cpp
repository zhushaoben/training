/*
obviously we construct some trees and other edges assigned 1e9 can satisfy this problem

the edge that du equal to dv can be added to tree firstly

and for node x if we can find a node v that have added and dv<=dx 
then we can assign dv to edge(xv) and xv have different color

显然，只有d_u和d_v相等的边才能作为生成树的切入点，随后生成一颗树即可。

相邻的点如果能保证权值不减，就放不同的颜色，边放相应的权值。
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=1e9;
struct Edge{
	int next,to;
}edge[N<<2];
struct Node{
	int w,x;
	bool operator < (const Node &b)const{return w<b.w;}
}a[N];
int fi[N],se=1,c[N],d[N],ans[N<<1];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x){
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(c[v]){c[x]=c[v]^3,ans[i>>1]=d[x];return;}
		if(d[v]==d[x]){c[x]=1,c[v]=2,ans[i>>1]=d[x];return;}
	}
	puts("-1");exit(0);
}
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",d+i+1),a[i].w=d[i+1],a[i].x=i+1;
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v);
	sort(a,a+n);
	for(int i=0;i<n;i++)if(!c[a[i].x])dfs(a[i].x);
	for(int i=1;i<=n;i++)if(c[i]==1)putchar('B');else putchar('W');
	for(int i=1;i<=m;i++)printf("\n%d",ans[i]?ans[i]:inf);
	return 0;
} 
