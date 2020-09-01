#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
struct Node{
	int next,to;
}edge[N*2];
int fi[N],se,fa[N][20],que[N*2],depth[N],sk[N],sk1[N],k,k1;
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x){
	if(depth[x]<=k1)que[depth[x]+N]++;
	for(int i=1;i<20;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		if(!fa[x][i])break;
	}
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x][0])continue;
		fa[v][0]=x;depth[v]=depth[x]+1,dfs(v);
	}
}
int up(int x,int k){
	for(int i=19;~i;i--)if(k&(1<<i))x=fa[x][i];
	return x;
}
int ans,w,s;
void dfs1(int x){
	s--;
	if(k&1){
		que[s+k1]+=sk[x];
		que[s+k1+2]-=sk[x];
		w-=que[s+k1+2];
		w+=sk[x];
	}
	else{
		que[s+k1]+=sk[x];
		que[s+k1-1]+=sk1[x];
		que[s+k1+1]-=sk[x];
		que[s+k1+2]-=sk1[x];
		w-=que[s+k1+1];
		w+=sk[x],w+=sk1[x];
	}
	ans=max(ans,w);
	if(k&1)que[s+k1-1]+=sk1[x],w+=sk1[x];
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa[x][0])continue;
		dfs1(v);
	}
	if(k&1){
		que[s+k1]-=sk[x];
		que[s+k1-1]-=sk1[x];
		que[s+k1+2]+=sk[x];
		w+=que[s+k1+2];
		w-=sk[x];
		w-=sk1[x];
	}
	else{
		que[s+k1]-=sk[x];
		que[s+k1-1]-=sk1[x];
		que[s+k1+1]+=sk[x];
		que[s+k1+2]+=sk1[x];
		w+=que[s+k1+1];
		w-=sk[x],w-=sk1[x];
	}
	s++;
}
void work(){
	int n,u,v;scanf("%d%d",&n,&k);
	memset(fi,0,sizeof(fi)),memset(sk1,0,sizeof(sk1)),memset(sk,0,sizeof(sk)),se=0;
	memset(que,0,sizeof(que));
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	if(k==1){
        int ans=(n==1?0:n-2);
        printf("%d\n",ans);return;
    }
	k1=k/2;
	dfs(1);
	for(int i=1;i<=n;i++){sk[up(i,k1)]++,sk1[up(i,k1-1)]++;}
	ans=w=0;s=N;
	for(int i=0;i<=k1;i++)w+=que[N+i];
	for(int i=fi[1];i;i=edge[i].next){
		int v=edge[i].to;
		dfs1(v);
	}
	printf("%d\n",n-ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
/*
1
8 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
*/
