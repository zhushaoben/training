#include<bits/stdc++.h>
using namespace std;
#define mo 998244353
#define maxn 100005
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],se;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
LL a[maxn],p[maxn],fp[maxn],seed[maxn],inv[maxn];
int depth[maxn],fa[maxn][18];
void dfs(int x){
	p[x]=(p[fa[x][0]]*seed[1]+a[x])%mo,fp[x]=(fp[fa[x][0]]+seed[depth[x]]*a[x])%mo;
	for(int i=1;;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		if(!fa[x][i])break;
	}
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x][0])continue;
		fa[v][0]=x,depth[v]=depth[x]+1;dfs(v);
	}
}
vector<int>V[maxn];
void up(int &x,int d){
    for(int i=17;i>=0;i--){
        if(d&(1<<i))x=fa[x][i];
    }
}
int lca(int u,int v){
    if(depth[u]>depth[v])swap(u,v);
    up(v,depth[v]-depth[u]);
    for(int i=17;i>=0;i--){
        if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    }
    if(u!=v)return fa[u][0];
    return u;
}
bool check(int u,int v){
	int l=lca(u,v);
	LL w=(p[u]-p[fa[l][0]]*seed[depth[u]-depth[l]+1])%mo+(fp[v]-fp[l])*((depth[u]-depth[l]*2>=0)?seed[depth[u]-depth[l]*2]:inv[-depth[u]+depth[l]*2])%mo;
	swap(u,v);w=((w%mo)+mo)%mo;
	LL w1=(p[u]-p[fa[l][0]]*seed[depth[u]-depth[l]+1])%mo+(fp[v]-fp[l])*((depth[u]-depth[l]*2>=0)?seed[depth[u]-depth[l]*2]:inv[-depth[u]+depth[l]*2])%mo;
	w1=((w1%mo)+mo)%mo;
	return w==w1;
}
void work(){
	int n,u,v;scanf("%d",&n);
	memset(fi,0,sizeof(fi)),se=0;
	for(int i=1;i<=n;i++)V[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",a+i),V[a[i]].push_back(i);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1);int ans=0;
	for(int i=1;i<=n;i++){
		int s=V[i].size();
		for(int j=0;j<s;j++)for(int k=j+1;k<s;k++){
			if(check(V[i][j],V[i][k]))ans++;
		}
	}
	printf("%d\n",ans+n);
}
int main(){
	int t;scanf("%d",&t);
	seed[1]=23,seed[0]=inv[0]=1,inv[1]=Pow(seed[1],mo-2);for(int i=2;i<maxn;i++)seed[i]=seed[i-1]*seed[1]%mo,inv[i]=inv[i-1]*inv[1]%mo;
	while(t--)work();
	return 0;
}
/*
4
1 2 2 1
1 2
2 3
2 4
*/
