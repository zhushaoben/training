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
int search(int x){//����xָ��Ľڵ� 
	if(find[x]==x)return x;
	return find[x]=search(find[x]);
}
void Tarjan(int x,int f){//Tarjan��LCA 
	find[x]=x,vis[x]=1;//��ǰ�ڵ��Ѿ���������ָ���Լ� 
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==f)continue;
		Tarjan(v,x);
	}
	for(int i=qi[x];i;i=q[i].next){
		int v=q[i].to;
		if(vis[v])lca[i>>1]=search(v);//���ѯ�ʵ���һ�����Ѿ�������,��LCA=search(v) 
	}
	find[x]=f;//��ǰ�ڵ㼰����ָ���� 
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
		add_q(u,v);//��ѯ�����ڽӱ�洢 
	}
	Tarjan(s,0); 
	for(int i=1;i<=m;i++)printf("%d\n",lca[i]);
	return 0;
} 
