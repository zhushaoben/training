#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
struct Edge{
	int next,to;
}edge[maxn*4],e[maxn*2]; 
int fi[maxn*2],se,l[maxn*2],r[maxn*2],size[maxn*2],head[maxn],f[maxn],si;
inline void add_edge(int u,int v,int fi[],Edge edge[],int &se){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;} 
inline void add(int u,int v,int fi[]=fi,Edge edge[]=edge,int &se=se){add_edge(u,v,fi,edge,se),add_edge(v,u,fi,edge,se);}
void dfs(int x,int fa){
	size[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);l[x]=min(l[x]?l[x]:maxn,l[v]),r[x]=max(r[x],r[v]),size[x]+=size[v];
	}
	add_edge(r[x],x,head,e,si);
}
void work(){
	int n,a,b,x;scanf("%d%d",&n,&a);
	for(int i=2;i<=a;i++)scanf("%d",&x),add(i,x);
	for(int i=1;i<=n;i++)scanf("%d",&x),l[x]=r[x]=i;
	scanf("%d",&b);
	for(int i=2;i<=b;i++)scanf("%d",&x),add(i+a,x+a);
	for(int i=1;i<=n;i++)scanf("%d",&x),l[x+a]=r[x+a]=i;
	dfs(1,0),dfs(a+1,0);size[1]--,size[a+1]--;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=head[i];j;j=e[j].next){
			int v=e[j].to;
			f[i]=max(f[i],f[l[v]-1]+size[v]);
		}
	}
	printf("%d\n",f[n]);
}
int main(){
	int t=1;//scanf("%d",&t);
	while(t--)work();
	return 0;
} 
