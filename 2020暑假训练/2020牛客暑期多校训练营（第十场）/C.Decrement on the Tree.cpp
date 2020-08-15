#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long LL;
struct Edge{
	int next,to,w;
}edge[N*2];
int fi[N],se;
inline void add_edge(int u,int v,int w){edge[++se]={fi[u],v,w},fi[u]=se;}
inline void add(int u,int v,int w){add_edge(u,v,w),add_edge(v,u,w);}
LL f[N],ans=0;
multiset<int>S[N];
LL calc(int x){
	auto it=S[x].end();
	int w=*(--it);
	if(w*2>f[x])return w;
	else return (f[x]-1)/2+1;
}
void dfs(int x,int fa){
	ans+=calc(x);
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		ans-=edge[i].w;dfs(v,x);
	}
}
int main(){
	int n,q,u,v,w,x,y;scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++)scanf("%d%d%d",&u,&v,&w),add(u,v,w),f[u]+=w,f[v]+=w,
	S[u].insert(w),S[v].insert(w);
	dfs(1,0);
	printf("%lld\n",ans);
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&w);
		v=edge[x*2].to;u=edge[x*2-1].to,y=edge[x*2].w;
		edge[x*2].w=edge[x*2-1].w=w;
		ans-=w-y,ans-=calc(u),ans-=calc(v);
		f[v]+=w-y,f[u]+=w-y,S[v].erase(S[v].find(y)),S[u].erase(S[u].find(y));
		S[v].insert(w),S[u].insert(w);
		ans+=calc(u),ans+=calc(v);
		printf("%lld\n",ans);
	}
	return 0;
} 
