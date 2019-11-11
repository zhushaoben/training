/*
we build a graph and find the max flows
if flow ==n-1 then we can find a plan
else we can't find
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 2000
#define maxm 10000
#define inf 0x1fffffff 
struct Edge{
	int next,to,fl;
}e[maxn*2+5],edge[maxm*4];
int head[maxn+5],si,fi[maxn*2+5],se=1;
inline void add_edge(int u,int v,int fl,int fi[],Edge edge[],int &se){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,edge[se].fl=fl;};
inline void add(int u,int v,int fl,int fi[],Edge edge[],int &se){add_edge(u,v,fl,fi,edge,se),add_edge(v,u,0,fi,edge,se);}
struct Node{
	int v,fi,si,x;
}a[maxn+5];
int b[maxm+5],Si,c[maxn+5],d[maxn+5],num[maxn+5],n,k,k1,s,t;
void read(){//read and do a discretization
	scanf("%d%d",&n,&k),k1=k;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].v,&a[i].si);a[i].fi=Si,add(i,a[i].v,0,head,e,si);
		for(int j=0;j<a[i].si;j++)scanf("%d",b+Si++);
	}
	for(int i=0;i<k;i++)scanf("%d",c+i),d[i]=c[i];
	sort(d,d+k);int si=unique(d,d+k)-d;k=si;
	for(int i=0;i<k1;i++)c[i]=lower_bound(d,d+k,c[i])-d,num[++c[i]]++;
	for(int i=0;i<Si;i++)si=lower_bound(d,d+k,b[i])-d,b[i]=(b[i]==d[si]?si+1:-1);
}
int st;
void dfs(int x,int fa){//find the only circle 
	a[x].x=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;if(v==fa)continue;
		if(a[v].x){st=v;return;}
		dfs(v,x);
		if(st){if(st==v)a[x].x=0,st=x;return;}
	}
	a[x].x=0;
}
int L,R;
void build(){//build the graph
	s=0,t=k+n+2;
	for(int i=1;i<=k;i++)add(0,i,num[i],fi,edge,se);
	dfs(1,0);int w=0;L=se+1;
	for(int i=1;i<=n;i++)for(int j=0;j<a[i].si;j++)if(b[a[i].fi+j]!=-1)add(b[a[i].fi+j],k+i,1,fi,edge,se);
	R=se-1;
	for(int i=1;i<=n;i++)add(k+i,t-a[i].x,1,fi,edge,se),w+=a[i].x;
	add(n+k+1,n+k+2,w-1,fi,edge,se);
}
int que[maxn*3],S,T,dis[maxn*3],cur[maxn*3];
bool bfs(){
	S=T=0;memset(dis,0,sizeof(dis));
	que[T++]=s;dis[s]=1;
	for(int i=0;i<=t;i++)cur[i]=fi[i];
	while(S<T){
		int u=que[S++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].fl&&!dis[v])dis[v]=dis[u]+1,que[T++]=v;
		}
	}
	return dis[t];
}
int dfs1(int x,int w){
	if(x==t||!w)return w;
	int flow=0,w1;
	for(int &i=cur[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(dis[v]!=dis[x]+1||!edge[i].fl)continue;
		w1=dfs1(v,min(w,edge[i].fl));
		edge[i].fl-=w1,edge[i^1].fl+=w1,flow+=w1,w-=w1;
		if(!w)break;
	}
//	if(!flow)dis[u]=-1; // a little optimization
	return flow;
} 
int dinic(){//find the max flows
	int ans=0;
	while(bfs())
		ans+=dfs1(s,inf);
	return ans;
}
vector<int>v[maxn+5];int first[maxn+5];
int main(){
	read();
	build();
	if(dinic()!=n-1)return puts("-1"),0;
	// print the plan
	for(int i=L;i<=R;i+=2){
	if(!edge[i].fl)v[edge[i^1].to].push_back(edge[i].to-k);}
	for(int i=0;i<k1;i++){
		int x=c[i];
		if(first[x]<v[x].size())printf("%d %d\n",v[x][first[x]],a[v[x][first[x]]].v),first[x]++;
		else puts("0 0");
	}
	return 0;
}
