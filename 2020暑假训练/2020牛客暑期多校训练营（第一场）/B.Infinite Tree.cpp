#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
struct Edge{
	int next,to;
}edge[N];
int n,w[N],fi[N],se,depth[N],st[N],top,si,lcadep[N];
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
int prim[N/5],prime_n,midiv[N]; 
void prime(){
    for(int i=2;i<N;i++){
        if(!midiv[i])prim[prime_n++]=i,midiv[i]=i;
        for(int j=0;j<prime_n&&i*prim[j]<N;j++){
            midiv[prim[j]*i]=prim[j];
            if(i%prim[j]==0)break;
        }
    }
}
const int N_FENWICK = 1e5;
int c[N_FENWICK+5];
inline int lowbit(int x){return x&(-x);}
void add(int x,int num){while(x<=N_FENWICK)c[x]+=num,x+=lowbit(x);}
int sum(int x){
	int ans=0;
	while(x)ans+=c[x],x-=lowbit(x);
	return ans;
}
LL ans;
void build(){
	for(int i=2;i<=n;i++){//calculate the lca of i! and (i-1)!
		depth[i]=depth[i-1]+1;
		int x=i;while(x!=midiv[x])x/=midiv[x],depth[i]++;
		lcadep[i]=sum(n)-sum(x-1);
		x=i;while(x>1)add(midiv[x],1),x/=midiv[x];
	}
	si=n;st[top=1]=1;//build the virtual tree
	for(int i=2;i<=n;i++){
		while(top>1&&depth[st[top-1]]>=lcadep[i])
			add_edge(st[top-1],st[top]),top--;
		if(depth[st[top]]!=lcadep[i]){
			depth[++si]=lcadep[i],w[si]=0;
			add_edge(si,st[top]),st[top]=si;
		}
		st[++top]=i;
	}
	while(top>1)add_edge(st[top-1],st[top]),top--;
}
void dfs(int x,int fa){
	ans+=1ll*w[x]*depth[x];
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);w[x]+=w[v];
	}
}
void dfs1(int x,int fa){
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		if((w[v]<<1)>w[1]){
			ans-=1ll*((w[v]<<1)-w[1])*(depth[v]-depth[x]);
			dfs1(v,x);
		}
	}
}
void init(){ans=se=0,memset(fi,0,sizeof(int)*(n*2+5)),memset(c,0,sizeof(int)*(n+5));}
void work(){
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	init();build();
	dfs(1,0),dfs1(1,0);
	printf("%lld\n",ans);
}
int main(){
	prime();
	while(~scanf("%d",&n))work();
	return 0;
} 
