#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Edge{int next,to;}edge[N*2];
int fi[N],se,a[N],ans[N],b[N],s;
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	int w=lower_bound(b,b+s,a[x])-b,w1=b[w];
	b[w]=a[x];ans[x]=s=max(s,w+1);
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);s=ans[x];
	}
	b[w]=w1;
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}
