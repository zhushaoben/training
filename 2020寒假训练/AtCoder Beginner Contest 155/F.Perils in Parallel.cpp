/*
使用差分讲每次操作变成修改两个数，然后在这两个数间连边
在构造的图中dfs判断是否有可行解 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int a,b;
	bool operator < (const Node &c)const{return a<c.a;} 
}a[N];
struct Edge{
	int next,to;
}edge[N*4];
int c[N],fi[N],se=1;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;} 
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
bool vis[N],use[N*2];
bool dfs(int x){
	vis[x]=1;
	int w=a[x-1].b;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]&&dfs(v))w^=1,use[i>>1]^=1;
	}
	return w;
}
int main(){
	int n,m,l,r;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].a,&a[i].b);
	sort(a,a+n);
	for(int i=n;i;i--)c[i]=a[i].a,a[i].b^=a[i-1].b;c[n]=1e9+5,c[0]=a[0].a;
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		l=lower_bound(c,c+n+1,l)-c+1,r=upper_bound(c,c+n+1,r)-c+1;
		add(l,r);
	}
	for(int i=1;i<=n+1;i++)if(!vis[i]&&dfs(i))return puts("-1"),0;
	int num=0;for(int i=1;i<=m;i++)if(use[i])num++;
	printf("%d\n",num);
	for(int i=1;i<=m;i++)if(use[i])printf("%d ",i);
	return 0;
}
