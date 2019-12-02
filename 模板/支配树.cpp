#include<cstdio>
#define maxn 100005
#define maxm 500005
struct Edge{
	int next,to;
}edge[maxm],edge_pr[maxm],road[maxn];
int n,m,fi[maxn],se,fi_pr[maxn],se_pr,dfn[maxn],si,a[maxn],fa[maxn],head[maxn],sr;
int sdom[maxn],idom[maxn],myfind[maxn],mi_sdom[maxn],son[maxn];
inline void add_edge(int u,int v){//存图的边 
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;
}
inline void add_edge_pr(int u,int v){//存图的反向边 
	edge_pr[++se_pr].next=fi_pr[u],edge_pr[se_pr].to=v,fi_pr[u]=se_pr;
}
inline void add_road(int u,int v){//指向sdom为自己的点 
	road[++sr].next=head[u],road[sr].to=v,head[u]=sr;
}
void dfs(int x){//预处理出dfs树 
	a[dfn[x]=++si]=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!dfn[v])dfs(v),fa[v]=x;
	}
}
int Find(int x){//带权并查集路径压缩 
	if(x==myfind[x])return x;//dfn小于正在求的点,返回自己 
	int y=Find(myfind[x]);//返回祖先中dfn小于正在求的点的最深的点 
	if(dfn[sdom[mi_sdom[myfind[x]]]]<dfn[sdom[mi_sdom[x]]])mi_sdom[x]=mi_sdom[myfind[x]];//更新dfn大于正在求的点的最小的sdom 
	return myfind[x]=y;
}
inline void build(){
	for(int i=1;i<=n;i++)myfind[i]=sdom[i]=mi_sdom[i]=i;
	dfs(1);
	for(int j=si;j>1;j--){//必须按dfs序倒着算 
		int x=a[j];
		for(int i=fi_pr[x];i;i=edge_pr[i].next){//v为能到达x的点 
			int v=edge_pr[i].to;
			if(!dfn[v]) continue;
			Find(v);
			if(dfn[sdom[mi_sdom[v]]]<dfn[sdom[x]])sdom[x]=sdom[mi_sdom[v]];
			//若dfn[v]<dfn[x]则sdom[mi_sdom[v]]==v,否则sdom[mi_sdom[v]]为sdom (u)使得u为v的祖先,于是可求出sdom 
		}
		add_road(sdom[x],x);
		myfind[x]=fa[x],x=a[j-1];
		for(int i=head[x];i;i=road[i].next){
			int v=road[i].to;
			Find(v);//更新后mi_sdom为v到x路径中sdom最小的点 
			if(sdom[mi_sdom[v]]==x)idom[v]=x;//v到sdom[v]路径中没有sdom>x的点,则idom[v]=sdom[v]=x; 
			else idom[v]=mi_sdom[v];//否则idom[v]=idom[mi_sdom[v]](路径中sdom最小点的idom) 但idom[mi_sdom[v]]可能还没求出来,所以先记录一下 
		}
	}
	for(int i=2;i<=si;i++){
		int x=a[i];
		if(idom[x]!=sdom[x])idom[x]=idom[idom[x]];//将idom[v]=idom[mi_sdom[v]]没完成的步骤不上 
	}
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v),add_edge(u,v),add_edge_pr(v,u);
	}
	build();//build后idom就求出来了，然后根据题目进行计算
	return 0;
}
