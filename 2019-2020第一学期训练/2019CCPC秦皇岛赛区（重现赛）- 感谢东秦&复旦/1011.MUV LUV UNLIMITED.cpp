#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
struct Edge{
	int next,to;
}edge[maxn+5];
int fi[maxn+5],se,depth[maxn+5],num[maxn+5],ma;
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;
}
void dfs(int x){
	num[depth[x]]++;ma=max(ma,depth[x]);
	for(int i=fi[x];i;i=edge[i].next)depth[edge[i].to]=depth[x]+1,dfs(edge[i].to);
}
void work(){
	int n,u,d=1;scanf("%d",&n);fi[1]=se=0;
	memset(num,0,sizeof(int)*(n+5));ma=0;
	for(int i=2;i<=n;i++)scanf("%d",&u),add_edge(u,i),fi[i]=0;
	depth[1]=1,dfs(1);
	for(int i=ma;;i--,d=!d){
		if(!num[i]){d=!d;break;}
		if(num[i]>1)break;
	}
	if(d)puts("Takeru");
	else puts("Meiya");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
