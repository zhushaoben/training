#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,inf=0x3fffffff;
struct Edge{
	int next,to,fl;
}edge[N*30];
int fi[N],fi1[N],a[N],b[N],c[N],se,S,T,T1,dis[N];
inline void add_edge(int u,int v,int fl=inf){edge[++se]={fi[u],v,fl},fi[u]=se;}
inline void add(int u,int v,int fl){add_edge(u,v,fl),add_edge(v,u,0);}
void init(int si){memset(fi,0,sizeof(int)*(si+5)),se=1,S=si+1,T=si+2;}
int que[N],s,t;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
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
	for(int i=1;i<=T;i++)fi1[i]=fi[i];
	return dis[T]!=-1;
}
int dfs(int x,int low){
	int tmp=low,w;
	if(x==T)return low;
	for(int &i=fi1[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(dis[v]==dis[x]+1&&edge[i].fl){
			w=dfs(v,min(tmp,edge[i].fl));
			edge[i].fl-=w,edge[i^1].fl+=w,tmp-=w;
		}
	}
	return low-tmp;
}
void work(){
	int n=read(),si;
	for(int i=0;i<n;i++)
		c[i<<1]=a[i]=read(),c[i<<1|1]=b[i]=read();
	sort(c,c+(n<<1)),si=unique(c,c+(n<<1))-c;
	for(int i=0;i<n;i++){
		a[i]=lower_bound(c,c+si,a[i])-c+1;
		b[i]=lower_bound(c,c+si,b[i])-c+1;
	}
	init(si+n);
	for(int i=0;i<n;i++){
		add(i+1,T,1);
		add(n+a[i],i+1,1);
		add(n+b[i],i+1,1);
	}
	for(int i=1;i<=si;i++)add(S,n+i,1);
	int ans=0,tmp;
	while(bfs())
		while(tmp=dfs(S,inf))ans+=tmp;
	printf("Case #%d: %d\n",++T1,ans);
}
int main(){
	freopen("a.out","r",stdin);
	int t=read();
	while(t--)work();
	return 0;
}
