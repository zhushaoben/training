#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
struct Edge{
	int next,to,w;
}edge[N<<1];
struct Node{
	LL a,b;
	bool operator <(const Node &c)const{
		if(a!=c.a)return a<c.a;
		return b<c.b;
	}
}que[N],f[N];
int n,k,fi[N],se,top;
inline void add_edge(int u,int v,int w){edge[++se]={fi[u],v,w},fi[u]=se;}
inline void add(int u,int v,int w){add_edge(u,v,w),add_edge(v,u,w);}
LL ans;
void dfs(int x,int fa){
	int t=top;f[x]={0,0};
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);que[top++]={f[v].a+edge[i].w,0};
	}
	sort(que+t,que+top);
	LL w=0;
	for(int i=max(t,top-k+1);i<top;i++)w+=que[i].a;
	f[x].a=w;
	if(fa==0){
		LL w=0;
		for(int i=t;i<top;i++)w+=que[i].a;
		ans=max(w,ans);
	}
	top=t;
}
void work(){
	scanf("%d%d",&n,&k);
	memset(fi,0,sizeof(int)*(n+2)),se=0,ans=0,top=0;
	int u,v,w; 
	for(int i=1;i<n;i++)scanf("%d%d%d",&u,&v,&w),add(u,v,w);
	if(k==0){puts("0");return;}
	for(int i=1;i<=n;i++)
		dfs(i,0);
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
