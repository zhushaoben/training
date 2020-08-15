#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,INF=0x3fffffff;
struct Edge
{
    int v,next;
}edge[N*30];
int a[N],b[N],c[N],T1,n1;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
int cnt,head[N];
int xline[N],yline[N],dy[N],dx[N];///xline表示与x配对的y编号,yline表示与y配对的x编号,dy,dx表示在各自集合里的编号
int vis[N],dis;


void addedge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(xline,-1,sizeof(xline));
    memset(yline,-1,sizeof(yline));
}
int bfs()
{
    queue<int>que;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=1;i<=n1;i++)
    {
        if(xline[i]==-1)
        {
            que.push(i);
            dx[i]=0;
        }
    }
    while(!que.empty())
    {
        int u=que.front();que.pop();
        if(dx[u]>dis) break;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if(yline[v] == -1) dis = dy[v];
                else
                {
                    dx[yline[v]] = dy[v]+1;
                    que.push(yline[v]);
                }
            }
        }
    }
    return dis!=INF;
}
int can(int t)
{
    for(int i=head[t];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(!vis[v]&&dy[v]==dx[t]+1)
        {
            vis[v]=1;
            if(yline[v]!=-1&&dy[v]==dis) continue;
            if(yline[v]==-1||can(yline[v]))
            {
                yline[v]=t,xline[t]=v;
                return 1;
            }
        }
    }
    return 0;
}
int Maxmatch()///最大匹配
{
    int ans=0;
    while(bfs())
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n1;i++)
            if(xline[i]==-1&&can(i))
                ans++;
    }
    return ans;
}
void work(){
	int n=read(),si;init();
	for(int i=0;i<n;i++)
		c[i<<1]=a[i]=read(),c[i<<1|1]=b[i]=read();
	sort(c,c+(n<<1)),si=unique(c,c+(n<<1))-c;
	for(int i=0;i<n;i++){
		a[i]=lower_bound(c,c+si,a[i])-c+1;
		b[i]=lower_bound(c,c+si,b[i])-c+1;
	}
	for(int i=0;i<n;i++){
		addedge(n+a[i],i+1);
		addedge(n+b[i],i+1);
	}
	n1=n+si;
	printf("Case #%d: %d\n",++T1,Maxmatch());
}
int main(){
//	freopen("a.out","r",stdin);
	int t=read();
	while(t--)work();
	return 0;
}
