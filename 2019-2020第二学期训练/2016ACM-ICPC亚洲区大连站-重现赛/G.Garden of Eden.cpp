#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,n,k,s,c[N],t,vis[N],size[N];long long f[1<<10];
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	vis[x]=t;size[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa||(t&(1<<c[v])))continue;
		dfs(v,x),size[x]+=size[v];
	}
}
int main(){
	while(~scanf("%d%d",&n,&k)){
		int u,v;s=(1<<k)-1;memset(fi,0,sizeof(int)*(n+1)),se=0,memset(vis,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++)scanf("%d",c+i),c[i]--;
		for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
		if(k==1){printf("%lld\n",1ll*n*n);continue;}
		for(t=1;t<=s;t++){
			f[t]=0;
			for(int i=1;i<=n;i++)
				if(vis[i]!=t&&!(t&(1<<c[i])))dfs(i,0),f[t]+=1ll*size[i]*size[i];
		}
		long long ans=1ll*n*n;
		for(int i=1;i<=s;i++){
			int w=0;
			for(int j=0;j<k;j++)if(i&(1<<j))w++;
			if(w&1)ans-=f[i];
			else ans+=f[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
