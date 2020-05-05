#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=998244353,inv=499122177;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,rt,mx,fa[N],f[N][3][3],tmp[3][3];
//f[i][j][k]表示i子树中有达到d==-m/2和m/2深度的节点个数(2代表多个
//it's easy to prove f[i][j][k]=f[i][k][j]
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int d){
	if(d>mx)mx=d,rt=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x])continue;
		fa[v]=x,dfs(v,d+1);
	}
}
void dp(int x,int d,int fa){
	if(d==mx/2)f[x][1][1]=1;
	else f[x][0][0]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dp(v,d+1,x);
		memset(tmp,0,sizeof(tmp));
		for(int t1:{0,1,2})for(int t2:{0,1,2})for(int s1:{0,1,2})for(int s2:{0,1,2}){
			for(int k:{0,1,2}){//0 indicate d[u]==d[v],1 indicate d[v]==d[u]-1,2 indicate d[v]==d[u]+1
				int w1=min(2,t1+s1*(k==1)),w2=min(2,t2+s2*(k==2));
				(tmp[w1][w2]+=1ll*f[x][t1][t2]*f[v][s1][s2]%mo)%=mo;
			}
		}
		memcpy(f[x],tmp,sizeof(tmp));
	}
}
int main(){
	int n,u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	mx=fa[rt]=0,dfs(rt,0);
	for(int i=0;i<mx/2;i++)rt=fa[rt];
	if(mx&1){
		u=rt,v=fa[rt];
		dp(u,0,v),dp(v,0,u);
		printf("%d\n",(1ll*f[u][1][0]+f[u][1][1]+f[u][1][2])*(1ll*f[v][1][0]+f[v][1][1]+f[v][1][2])%mo);
	}
	else{
		dp(rt,0,0);
		printf("%d\n",1ll*f[rt][1][1]*inv%mo);
	}
	return 0;
}
