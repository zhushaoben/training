#include<cstdio>
#define maxn 500005
struct Edge{
	int next,to;
}edge[maxn*2],q[maxn*2];
int n,m,fi[maxn],se,qi[maxn],sq=1,find[maxn],lca[maxn];
bool vis[maxn];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
	edge[++se].next=fi[v],edge[se].to=u,fi[v]=se;
}
inline void add_q(int u,int v){
	q[++sq].next=qi[u],q[sq].to=v,qi[u]=sq,
	q[++sq].next=qi[v],q[sq].to=u,qi[v]=sq;
}
int search(int x){//查找x指向的节点 
	if(find[x]==x)return x;
	return find[x]=search(find[x]);
}
void Tarjan(int x,int f){//Tarjan求LCA 
	find[x]=x,vis[x]=1;//当前节点已经遍历，并指向自己 
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==f)continue;
		Tarjan(v,x);
	}
	for(int i=qi[x];i;i=q[i].next){
		int v=q[i].to;
		if(vis[v])lca[i>>1]=search(v);//如果询问的另一个点已经遍历过,则LCA=search(v) 
	}
	find[x]=f;//当前节点及子树指向父亲 
}
int main(){
	int u,v,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add_q(u,v);//将询问用邻接表存储 
	}
	Tarjan(s,0); 
	for(int i=1;i<=m;i++)printf("%d\n",lca[i]);
	return 0;
} 
