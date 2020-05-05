#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,depth[N],fa[N][19],a[N];
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x){
	for(int i=1;i;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		if(!fa[x][i])break;
	}
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x][0])continue;
		depth[v]=depth[x]+1,fa[v][0]=x,dfs(v);
	}
}
bool cmp(int i,int j){
	return depth[i]>depth[j];
}
void up(int &u,int v){
	int k=depth[u]-depth[v];
	if(k<=0)return;
	for(int i=0;i<19;i++)if(k&(1<<i))u=fa[u][i];
}
int main(){
	int n,m,u,v,k;scanf("%d%d",&n,&m); 
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	depth[1]=1;dfs(1);
	for(int i=0;i<m;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++)scanf("%d",a+j),a[j]=fa[a[j]][0];
		sort(a,a+k,cmp);
		bool fl=1;
		for(int j=0;j<k-1;j++){
			u=a[j],v=a[j+1];
			up(u,v);
			if(u!=v){fl=0;break;}
		}
		if(fl)puts("YES");
		else puts("NO");
	}
	return 0;
} 
