#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=1e9+7;
struct Edge{
	int next,to,w;
}edge[N*2];
int fi[N],se,fa[N],a[N],size[N];
inline void add_edge(int u,int v,int w){edge[++se]={fi[u],v,w},fi[u]=se;}
inline void add(int u,int v,int w){add_edge(u,v,w),add_edge(v,u,w);}
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int ans,n,si;
void dfs(int x,int f,int w){
	fa[x]=a[x];size[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==f)continue;
		dfs(v,x,edge[i].w);
		fa[x]+=fa[v],size[x]+=size[v];
	}
	(ans+=1ll*w*(1ll*fa[x]*(n-si-size[x]+fa[x])%mo+1ll*(size[x]-fa[x])*(si-fa[x])%mo)%mo)%=mo;
}
void work(){
	int m,u,v,x,y,w=1;scanf("%d%d",&n,&m);
	se=0,si=0;for(int i=1;i<=n;i++)fi[i]=0,fa[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",a+i),si+=a[i];
	for(int i=0;i<m;i++,(w<<=1)%=mo){
		scanf("%d%d",&u,&v);
		x=Find(u),y=Find(v);
		if(x==y)continue;
		fa[x]=y,add(u,v,w);
	}
	ans=0;dfs(1,0,0);
	printf("%d\n",ans*2%mo);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
