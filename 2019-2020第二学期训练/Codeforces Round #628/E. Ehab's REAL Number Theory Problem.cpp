#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int prim[N*5],prime_n,pre[N*10]; 
bool is_pr[N*10]={1,1};
void prime(){
    int m=1e6+1;
    for(int i=2;i<m;i++){
        if(!is_pr[i])prim[prime_n++]=i,pre[i]=i;
        for(int j=0;j<prime_n&&i*prim[j]<m;j++){
            is_pr[prim[j]*i]=1,pre[prim[j]*i]=prim[j];
            if(i%prim[j]==0)break;
        }
    }
}
struct Edge{
	int next,to;
}edge[N*2];
int fi[N*10],se,depth[N*10],ans=1e9,ma;
int vis[N*10];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x){
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(depth[v]){
			if(depth[x]-depth[v]>1)ans=min(ans,depth[x]-depth[v]+1);
			continue;
		}
		depth[v]=depth[x]+1;dfs(v);
	}
}
void work(int x){
	int a=pre[x],w=0,b=0,w1=0,c=sqrt(x),x1=x;ma=max(ma,c);
	if(c*c==x)puts("1"),exit(0);
	while(x%a==0)x/=a,w^=1;
	if(b=pre[x])while(x%b==0)x/=b,w1^=1;
	if(x>1)printf("W%d",x1),exit(0);
	if(!w)a=1;if(!w1)b=1;
	if(vis[a*b])ans=2;
	else vis[a*b]=1,add(a,b);
}
int que[N],s,t,fa[N*10];
void bfs(int x){
	s=t=0,que[t++]=x,vis[x]=x+1,depth[x]=0;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(vis[v]==x+1){
				if(v!=fa[u])ans=min(ans,depth[u]+depth[v]+1);
				continue;
			}
			fa[v]=u,vis[v]=x+1,depth[v]=depth[u]+1,que[t++]=v;
		}
	}
}
int main(){
	prime();
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),work(x);
	bfs(1);
	for(int i=0;prim[i]<=ma;i++)bfs(prim[i]);
	printf("%d",ans==1e9?-1:ans);
	return 0;
}
