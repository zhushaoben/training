/******************************************************************
点分治
******************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10005
struct Edge{
	int next,to,w;
}edge[maxn*2];
int fi[maxn],se,n,k,size[maxn],root,ma[maxn],sum,ans,depth[maxn];
int b[maxn],si;
bool vis[maxn];
inline void add_edge(int u,int v,int w){
	edge[++se].next=fi[u],edge[se].to=v,edge[se].w=w,fi[u]=se,
	edge[++se].next=fi[v],edge[se].to=u,edge[se].w=w,fi[v]=se;
}
int cal(int x){
	
}
void getroot(int x,int f){//找到当前树的重心 
	size[x]=1,ma[x]=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==f||vis[v])continue;//vis[v]=1表示不属于本棵树 
		getroot(v,x);
		size[x]+=size[v];ma[x]=max(ma[x],size[v]);//ma[x]为按x分开后最大子树的节点树 
	}
	ma[x]=max(ma[x],sum-size[x]);//sum-size[x]为父节点连接的子树的大小 
	if(ma[x]<ma[root])root=x;//更新重心 
}
void solve(int x){
	ans+=cal(x);vis[x]=1;//先统计过重心的答案 
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v])continue;
		sum=size[v];root=0;
		getroot(v,0);//递归找子树的重心
		solve(root);//统计子树的答案 
	}
}
int main(){
	sum = ma[0] = n;//初始化 
    root = 0;
    getroot(1,0);//找重心 
    solve(root);//点分治 
	return 0;
}
