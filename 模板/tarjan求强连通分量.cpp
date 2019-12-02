#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1005
struct Edge{
	int next,to;
}edge[maxn*maxn];
int fi[maxn],se,col[maxn],sc,sta[maxn],top,dfn[maxn],low[maxn],df;//colΪÿ�������ڵ�ǿ��ͨ����,staΪģ���ջ; 
bool vis[maxn];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;
}
void Tarjan(int x){
	dfn[x]=low[x]=++df,vis[x]=1,sta[++top]=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
        if(!dfn[v])Tarjan(v),low[x]=min(low[x],low[v]);//û�б����� 
        else if(vis[v])low[x]=min(low[x],dfn[v]);//����ջ�ڵ�Ҫô��low[v]<dfn[x]��Ҫô��������ͨ 
	}
	if(dfn[x]==low[x]){//��һ��ǿ��ͨ���� 
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
