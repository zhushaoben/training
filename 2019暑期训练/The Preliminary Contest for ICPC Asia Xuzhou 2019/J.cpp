#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define mo 1000000007
void Inverse(int p,int a[],int n){//线性求<=n的数%p意义下的逆元 
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=1ll*(p-p/i)*a[p%i]%p;
    }
}
struct Edge{
	int next,to;
}edge[maxn*2];
int inv[maxn],fi[maxn],se,depth[maxn],f[maxn];
inline void add_edge(int u,int v){
	edge[++se].to=v,edge[se].next=fi[u],fi[u]=se,
	edge[++se].to=u,edge[se].next=fi[v],fi[v]=se;
}
int power(int a,int b){//a^b%mo
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*a%mo;
        a=1ll*a*a%mo;
        b>>=1;
    }
    return ans;
}
void dfs(int x,int fa){
	int num=0;depth[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		num++;dfs(v,x);depth[x]=max(depth[x],depth[v]+1);
	}
	if(!num)f[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		if(depth[v]+1==depth[x])f[x]=(f[x]+1ll*f[v]*inv[num])%mo;
	}
	if(num)f[x]=1+power(mo+1-f[x],num);
}
int main(){
	int n,u,v;scanf("%d",&n);Inverse(mo,inv,n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	dfs(1,0);
	printf("%d\n",f[1]);
	return 0;
}
