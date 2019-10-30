#include<bits/stdc++.h>
using namespace std;
#define maxn 600
#define eps 1e-8
struct Edge{
	int from,next,to;
}edge[maxn*maxn/2+5];
int fi[maxn+5],se,si[maxn+5];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,si[u]++,edge[se].from=u;
}
double p1[maxn+5],e1[maxn+5],e2[maxn+5];
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	p1[1]=1;
	for(int i=1;i<=n;i++){
		if(p1[i]<eps)continue;
		e1[i]/=p1[i];
		for(int j=fi[i];j;j=edge[j].next)p1[edge[j].to]+=p1[i]/si[i],e1[edge[j].to]+=p1[i]*(e1[i]+1)/si[i];
	}
	double ans=e1[n],ans1=0;
	for(int i=n-1;i;i--){
		for(int j=fi[i];j;j=edge[j].next){
			e2[i]+=(e2[edge[j].to]+1)/si[i];
		}
	}
	for(int i=1,u,v;i<=se;i++){
		if(si[u=edge[i].from]==1)continue;
		v=edge[i].to;
		ans1=max(ans1,p1[u]*(e2[u]-(e2[u]-(e2[v]+1)/si[u])*si[u]/(si[u]-1)));
	}
	printf("%.10lf",ans-ans1);
	return 0;
}
