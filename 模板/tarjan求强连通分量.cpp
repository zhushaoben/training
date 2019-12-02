#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1005
struct Edge{
	int next,to;
}edge[maxn*maxn];
int fi[maxn],se,col[maxn],sc,sta[maxn],top,dfn[maxn],low[maxn],df;//col为每个点属于的强连通分量,sta为模拟的栈; 
bool vis[maxn];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;
}
void Tarjan(int x){
	dfn[x]=low[x]=++df,vis[x]=1,sta[++top]=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
        if(!dfn[v])Tarjan(v),low[x]=min(low[x],low[v]);//没有遍历过 
        else if(vis[v])low[x]=min(low[x],dfn[v]);//不在栈内的要么是low[v]<dfn[x]，要么不互相连通 
	}
	if(dfn[x]==low[x]){//有一个强联通分量 
		vis[x]=0,col[x]=++sc;
		while(sta[top]!=x){
			col[sta[top]]=sc,vis[sta[top--]]=0;
		}
		top--;
	}
}
int main(){
	return 0;
} 
