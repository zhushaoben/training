#include<bits/stdc++.h>
using namespace std;
const int N=8e5+5; 
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],la[N],se,n,m,fa[N];
inline void add_edge(int u,int v){
	edge[++se]={fi[u],v};if(!fi[u])la[u]=se;fi[u]=se;
}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void init(){
	memset(fi,0,sizeof(int)*(n+5)),memset(la,0,sizeof(int)*(n+5)),se=0;
	for(int i=0;i<n;i++)fa[i]=i;
}
void work(){
	scanf("%d%d",&n,&m);
	init();int u,v,q;
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&u);
		int w=0;if(Find(u)!=u)continue;
		for(int &i=fi[u];i!=w;i=edge[i].next){
			v=Find(edge[i].to);if(v==u)continue;
			if(fi[v]&&!w)w=fi[v];
			if(la[v])edge[la[u]].next=fi[v],la[u]=la[v];
			la[v]=fi[v]=0;fa[v]=u;
		}
	}
	for(int i=0;i<n;i++)printf("%d ",Find(i));
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
