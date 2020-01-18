#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define maxs 17
struct Node{
	int l,r,sl,sr,s;
}a[maxn][maxs],b[maxn][maxs],ans1,ans2;
struct Edge{
	int next,to;
}edge[maxn];
int fa[maxn][maxs],V[maxn],fi[maxn],se,depth[maxn],s1,s2;
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void merge1(Node &a,Node b,Node c,int s2,int s3){
	a.s=max(b.s,c.s),a.l=b.l,a.r=c.r,a.sl=b.sl,a.sr=c.sr;
	if(b.r<c.l){
		a.s=max(a.s,b.sr+c.sl);
		if(s2==b.s)a.sl=b.s+c.sl;
		if(s3==c.s)a.sr=c.s+b.sr;
	}
}
void merge2(Node &a,Node b,Node c,int s2,int s3){
	a.s=max(b.s,c.s),a.l=b.l,a.r=c.r,a.sl=b.sl,a.sr=c.sr;
	if(b.r>c.l){
		a.s=max(a.s,b.sr+c.sl);
		if(s2==b.s)a.sl=b.s+c.sl;
		if(s3==c.s)a.sr=c.s+b.sr;
	}
}
void dfs(int x){
	int f=fa[x][0];
	a[x][0]=b[x][0]={V[f],V[f],(f!=0),(f!=0),(f!=0)};
	for(int i=1;;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		merge1(a[x][i],a[x][i-1],a[fa[x][i-1]][i-1],1<<(i-1),1<<(i-1));
		merge2(b[x][i],b[x][i-1],b[fa[x][i-1]][i-1],1<<(i-1),1<<(i-1));
		if(!fa[x][i])break;
	}
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		depth[v]=depth[x]+1,dfs(v);
	}
}
void up(int &x,int d){
    for(int i=maxs-1;i>=0;i--){
        if(d&(1<<i))x=fa[x][i];
    }
}
int lca(int u,int v){
    if(depth[u]>depth[v])swap(u,v);
    up(v,depth[v]-depth[u]);
    for(int i=maxs-1;i>=0;i--){
        if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    }
    if(u!=v)return fa[u][0];
    return u;
}
void solve1(int v,int u){
	int k=depth[v]-depth[u];
	ans1={V[v],V[v],1,1,1},s1=1;
	for(int i=maxs-1;i>=0;i--){
		if(k&(1<<i)){
			merge1(ans1,ans1,a[v][i],s1,1<<i),s1+=1<<i;
			v=fa[v][i];
		}
	}
}
void solve2(int v,int u){
	int k=depth[v]-depth[u];
	ans2={V[v],V[v],1,1,1},s2=1;
	for(int i=maxs-1;i>=0;i--){
		if(k&(1<<i)){
			merge2(ans2,ans2,b[v][i],s2,1<<i),s2+=1<<i;
			v=fa[v][i];
		}
	}
}
void work(){
	int n,q,u,v;scanf("%d",&n);
	memset(fi,0,sizeof(int)*(n+5)),se=0;
	for(int i=1;i<=n;i++)scanf("%d",V+i);
	for(int i=2;i<=n;i++)scanf("%d",&fa[i][0]),add_edge(fa[i][0],i);
	dfs(1);scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&u,&v);
		int LCA=lca(u,v);
		solve1(u,LCA);
		solve2(v,LCA);
		printf("%d\n",max(max(ans1.s,ans2.s),ans1.sr+ans2.sr-1));
	}
	puts("");
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d:\n",i);
		work();
	}
	return 0;
} 
