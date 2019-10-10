#include<bits/stdc++.h>
using namespace std;
#define maxn 500000
#define mo 998244353
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*4];
int fi[maxn+5],se,depth[maxn+5],m;
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
	edge[++se].next=fi[v],edge[se].to=u,fi[v]=se;
}
LL pwr(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%mo;
		a=a*a%mo;b>>=1;
	}
	return ans;
}
LL ans=1;
void dfs(int x){
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!depth[v]){depth[v]=depth[x]+1,dfs(v);continue;}
		if(depth[v]<depth[x]&&depth[v]!=depth[x]-1)(ans*=pwr(2ll,depth[x]-depth[v]+1)-1)%=mo,m-=depth[x]-depth[v]+1;
	}
}
void work(){
	int n,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	for(int i=1;i<=n;i++)if(!depth[i])depth[i]=1,dfs(i);
	(ans*=pwr(2ll,m))%=mo;
	printf("%lld\n",ans);
}
int main(){
	work();
	return 0;
}
