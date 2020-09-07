/*
将放砖块转化为删边，假如两个黑块之间的公共边被删了，说明两者在同一块。

由于每删一条边砖块数 -1，那么问题就变成了最多能删多少条边，
由于没有 L 形的砖，所以需要保证每一个黑块处都不能删出 L 形，
这个问题可以转化一下：将边化点，让两个冲突的边之间连边，问题就变成了求最大独立集，
由于这是二分图，用网络流解决即可。
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=205,SI=N*N*2,inf=0x3fffffff;
struct Edge{
	int next,to,fl;
}edge[SI*10];
int fi[SI],se,S,T,dis[SI];
inline void add_edge(int u,int v,int fl=inf){edge[++se]={fi[u],v,fl},fi[u]=se;}
inline void add(int u,int v,int fl){add_edge(u,v,fl),add_edge(v,u,0);}
int que[SI],s,t;
bool bfs(){
	memset(dis,-1,(T+1)<<2);
	s=t=0;que[t++]=S,dis[S]=0;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].fl&&dis[v]==-1){
				dis[v]=dis[u]+1;
				que[t++]=v;
			}
		}
	}
	return dis[T]!=-1;
}
int dfs(int x,int low){
	int tmp=low,w;
	if(x==T)return low;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(dis[v]==dis[x]+1&&edge[i].fl){
			w=dfs(v,min(tmp,edge[i].fl));
			edge[i].fl-=w,edge[i^1].fl+=w,tmp-=w;
		}
		if(!tmp)break;
	}
	if(low==tmp)dis[x]=0;
	return low-tmp;
}
char s1[N][N];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s1[i]+1);
	for(int i=1;i<=m;i++)s1[n+1][i]=0;
	S=n*(m-1) +m*(n-1)+1,T=S+1,se=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i][j]=='#'){
				ans++;
				if(s1[i][j+1]=='#')add(S,(i-1)*(m-1)+j,1),ans--;
				if(s1[i+1][j]=='#')add(n*(m-1)+(i-1)*m+j,T,1),ans--;
			}
			for(int k=0;k<2;k++)for(int l=0;l<2;l++)
				if(s1[i][j-1+(k<<1)]=='#'&&s1[i-1+(l<<1)][j]=='#')add((i-1)*(m-1)+j-1+k,n*(m-1)+(i-2+l)*m+j,1);
			
		}
	}
	int tmp;
	while(bfs())
		while(tmp=dfs(S,inf))ans+=tmp;
	printf("%d\n",ans);
	return 0;
}
