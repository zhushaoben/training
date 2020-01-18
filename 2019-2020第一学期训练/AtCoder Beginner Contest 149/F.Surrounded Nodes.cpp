#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define mo 1000000007
#define LL long long
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],size[maxn],n,se,Pow[maxn];LL inv,ans;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
LL power(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%mo;
		a=a*a%mo,b>>=1;
	}
	return ans;
}
void dfs(int x,int fa){
	size[x]=1;
	LL w=1,w1=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x),size[x]+=size[v];
		(w-=inv*Pow[size[v]])%=mo,w1++;
	}
	(w-=inv*Pow[n-size[x]])%=mo;
	(w+=inv*w1+mo)%=mo;
	ans+=w*500000004%mo;
}
int main(){
	int u,v;scanf("%d",&n);
	Pow[0]=1;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v),Pow[i]=2ll*Pow[i-1]%mo;
	inv=power(Pow[n-1],mo-2);
	dfs(1,0);
	printf("%d",ans%mo);
	return 0;
}
