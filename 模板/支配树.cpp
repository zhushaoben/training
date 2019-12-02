#include<cstdio>
#define maxn 100005
#define maxm 500005
struct Edge{
	int next,to;
}edge[maxm],edge_pr[maxm],road[maxn];
int n,m,fi[maxn],se,fi_pr[maxn],se_pr,dfn[maxn],si,a[maxn],fa[maxn],head[maxn],sr;
int sdom[maxn],idom[maxn],myfind[maxn],mi_sdom[maxn],son[maxn];
inline void add_edge(int u,int v){//��ͼ�ı� 
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;
}
inline void add_edge_pr(int u,int v){//��ͼ�ķ���� 
	edge_pr[++se_pr].next=fi_pr[u],edge_pr[se_pr].to=v,fi_pr[u]=se_pr;
}
inline void add_road(int u,int v){//ָ��sdomΪ�Լ��ĵ� 
	road[++sr].next=head[u],road[sr].to=v,head[u]=sr;
}
void dfs(int x){//Ԥ�����dfs�� 
	a[dfn[x]=++si]=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!dfn[v])dfs(v),fa[v]=x;
	}
}
int Find(int x){//��Ȩ���鼯·��ѹ�� 
	if(x==myfind[x])return x;//dfnС��������ĵ�,�����Լ� 
	int y=Find(myfind[x]);//����������dfnС��������ĵ������ĵ� 
	if(dfn[sdom[mi_sdom[myfind[x]]]]<dfn[sdom[mi_sdom[x]]])mi_sdom[x]=mi_sdom[myfind[x]];//����dfn����������ĵ����С��sdom 
	return myfind[x]=y;
}
inline void build(){
	for(int i=1;i<=n;i++)myfind[i]=sdom[i]=mi_sdom[i]=i;
	dfs(1);
	for(int j=si;j>1;j--){//���밴dfs������ 
		int x=a[j];
		for(int i=fi_pr[x];i;i=edge_pr[i].next){//vΪ�ܵ���x�ĵ� 
			int v=edge_pr[i].to;
			if(!dfn[v]) continue;
			Find(v);
			if(dfn[sdom[mi_sdom[v]]]<dfn[sdom[x]])sdom[x]=sdom[mi_sdom[v]];
			//��dfn[v]<dfn[x]��sdom[mi_sdom[v]]==v,����sdom[mi_sdom[v]]Ϊsdom (u)ʹ��uΪv������,���ǿ����sdom 
		}
		add_road(sdom[x],x);
		myfind[x]=fa[x],x=a[j-1];
		for(int i=head[x];i;i=road[i].next){
			int v=road[i].to;
			Find(v);//���º�mi_sdomΪv��x·����sdom��С�ĵ� 
			if(sdom[mi_sdom[v]]==x)idom[v]=x;//v��sdom[v]·����û��sdom>x�ĵ�,��idom[v]=sdom[v]=x; 
			else idom[v]=mi_sdom[v];//����idom[v]=idom[mi_sdom[v]](·����sdom��С���idom) ��idom[mi_sdom[v]]���ܻ�û�����,�����ȼ�¼һ�� 
		}
	}
	for(int i=2;i<=si;i++){
		int x=a[i];
		if(idom[x]!=sdom[x])idom[x]=idom[idom[x]];//��idom[v]=idom[mi_sdom[v]]û��ɵĲ��費�� 
	}
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v),add_edge(u,v),add_edge_pr(v,u);
	}
	build();//build��idom��������ˣ�Ȼ�������Ŀ���м���
	return 0;
}
