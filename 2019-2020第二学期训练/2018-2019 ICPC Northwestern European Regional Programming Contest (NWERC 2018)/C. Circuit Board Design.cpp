#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const double eps=2e-4;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
double x[N],y[N],now;
void dfs(int u,int fa){
	x[u]=(now+=eps),y[u]=y[fa]+sqrt(1-(x[u]-x[fa])*(x[u]-x[fa]));
	for(int i=fi[u];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,u);
	}
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%.10lf %.10lf\n",x[i],y[i]);
	return 0;
} 
