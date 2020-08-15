#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[105][105],dis[105];//v是邻接矩阵，dis是bfs时分的层 
int q[2000],l,r;//BFS队列 ,首,尾 
int n;
bool bfs(){
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	l=0;r=1;
	q[0]=1;
	while(l<r){//队列不为空 
		int j=q[l++];
		for(int i=1;i<=n;i++){
			if(v[j][i]>0&&dis[i]==-1)dis[i]=dis[j]+1,q[r++]=i;
		}
	}
	if(dis[n]>0)return 1;//判断是否能到n 
	return 0;
}
bool dfs(int x,int low){//low为到当前节点最大流 
	int ans=0;
	if(x==n)return low;
	for(int i=1;i<=n;i++){
		if(v[x][i]&&dis[i]==dis[x]+1&&(ans=dfs(i,min(low,v[x][i])))){
			v[x][i]-=ans;v[i][x]+=ans;//边的最大流量更新 
			return ans;
		}
	}
	return ans;
}
int main(){
	int ans=0,tans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%d",v[i]+j);//邻接矩阵读边 
	}
	while(bfs()){//判断是否能到n 
		while(tans=dfs(1,0x7fffffff))ans+=tans;//用增广路更新 
	}
	printf("%d",ans);
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,inf=0x3fffffff;
struct Edge{
	int next,to,fl;
}edge[N*30];
int n,m,fi[N],se,S,T,dis[N];
inline void add_edge(int u,int v,int fl=inf){edge[++se]={fi[u],v,fl},fi[u]=se;}
inline void add(int u,int v,int fl){add_edge(u,v,fl),add_edge(v,u,0);}
void init(){memset(fi,0,sizeof(int)*(2*n+5)),se=1,S=n+1,T=n+2;}
int que[N],s,t;
bool bfs(){
	memset(dis,-1,sizeof(int)*(T+1));
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
	}
	return low-tmp;
}
int main(){
	
	int ans=0;
	while(bfs())
		while(tmp=dfs(S,inf))ans+=tmp;
	printf("%d\n",ans);
	
}
