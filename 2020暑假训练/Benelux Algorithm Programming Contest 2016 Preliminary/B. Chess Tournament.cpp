#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
struct Edge{
	int next,to;
}edge[N*5];
int fi[N],se,fa[N],vis[N],vis1[N];
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
vector<int>V[N];
void dfs(int x){
	if(vis1[x])return;
	vis[x]=1,vis1[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v]){puts("inconsistent");exit(0);}
		dfs(v);
	}
	vis[x]=0;
}
int main(){
	int n,m,u,v;char op[5];scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d%s%d",&u,op,&v);
		if(op[0]=='=')u=Find(u),v=Find(v),fa[u]=v;
		else if(op[0]=='<')V[u].push_back(v);
		else V[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		u=Find(i);
		for(auto x:V[i]){
			v=Find(x);
			add_edge(u,v);
		}
	}
	for(int i=0;i<n;i++)dfs(i);
	puts("consistent");
	return 0;
}
