#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge{
	int next,to;
}edge[N*4],edge1[N*4];
int fi[N],fi1[N],se;
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
	edge1[se].next=fi1[v],edge1[se].to=u,fi1[v]=se;
}
int main(){
	int n,m,u,v,ans=0;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	for(int i=1;i<n;i++){
		int a=0,b=0;
		for(int j=fi[i];j;j=edge[j].next)if(edge[j].to>i)a++;
		for(int j=fi1[i];j;j=edge1[j].next)if(edge1[j].to>i)b++;
		ans+=min(a,b);
	}
	printf("%d\n",ans);
	for(int i=1;i<n;i++){
		int a=0,b=0;
		for(int j=fi[i];j;j=edge[j].next)if(edge[j].to>i)a++;
		for(int j=fi1[i];j;j=edge1[j].next)if(edge1[j].to>i)b++;
		if(a>b){for(int j=fi1[i];j;j=edge1[j].next)if(edge1[j].to>i)printf("%d\n",j);}
		else for(int j=fi[i];j;j=edge[j].next)if(edge[j].to>i)printf("%d\n",j);
	}
	return 0;
}
