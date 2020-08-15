#include<bits/stdc++.h>
using namespace std;
const int N=55,M=205,inf=0x3f3f3f3f;
typedef long long LL;
struct Edge{
	int next,to,w,fl;
}edge[M];
int n,m,s,t,fi[N],se,dis[N],pre[N],flow[N];
bool vis[N];
inline char getc(void) { 
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
    int x=0; char ch=getc();
    while(ch<'0'||ch>'9') {if(ch<=0)return 0;ch=getc();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getc();}
    return x;
}
char ops[1 << 18], *opt = ops, *const opt_end = ops + (1 << 18);
inline void write_all(void) { 
    fwrite(ops, 1, opt - ops, stdout);
    opt = ops; return ;
}
inline void write(LL x) { 
    static char *p = new char[20]();
    do{ 
        *(++p) = (x % 10) | 0x30;
        x /= 10;
    }while(x);

    while(*p) { 
        *(opt++) = *(p--);
        if(opt == opt_end) write_all();
    }
    if(opt == opt_end) write_all();
}
inline void writec(char c){*(opt++)=c;if(opt == opt_end) write_all();}
inline void add_edge(int u,int v,int w,int fl){
	edge[++se]={fi[u],v,w,fl},fi[u]=se,
	edge[++se]={fi[v],u,-w,0},fi[v]=se;
}
bool SPFA(){
	deque<int> q;int sum=0,tot=1;
	memset(dis,0x3f,sizeof(dis)),memset(vis,0,sizeof(vis));
	q.push_back(s),vis[s]=1,dis[s]=0,flow[s]=inf,flow[t]=0;
	while(!q.empty()){
		int u=q.front();q.pop_front();
		if(dis[u]*tot>sum){//LLL优化 
			q.push_back(u);continue;
		}
		vis[u]=0,sum-=dis[u],tot--;
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].fl&&dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w,flow[v]=min(flow[u],edge[i].fl),pre[v]=i;//pre[i]记录路径上到达点i的边的编号
				if(vis[v])continue;
				vis[v]=1,sum+=dis[v],tot++;
				if(q.empty()||dis[v]>dis[q.front()])q.push_back(v);//SLF优化 
				else q.push_front(v);
			}
		}
	}
	if(flow[t]){//更新路径上的边的剩余流量 
		for(int i=pre[t];i;i=pre[edge[i^1].to]){
			edge[i].fl-=flow[t],edge[i^1].fl+=flow[t];
		}
	}
	return flow[t];
}
int ans[M],si,sum[M];
void init(){memset(fi,0,sizeof(int)*(n+5)),se=1,si=0;}
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void work(){
	s=1,t=n;init();
	int u,v,w,f;
	for(int i=0;i<m;i++)u=read(),v=read(),w=read(),add_edge(u,v,w,1);
	while(SPFA())ans[++si]=dis[t],sum[si]=sum[si-1]+ans[si];
	int q=read();
	for(int i=0;i<q;i++){
		u=read(),v=read();
		if(1ll*u*si<v){writec('N'),writec('a'),writec('N'),writec('\n');continue;}
		LL w=v/u,ans1=1ll*sum[w]*u+1ll*ans[w+1]*(v%u),g=gcd(ans1,v);
		write(ans1/g),writec('/'),write(v/g),writec('\n');
	}
}
int main(){
	while((n=read())&&(m=read()))work();
	write_all();
	return 0;
}
