#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Edge{
	int next,to,w;
}edge[N*2];
int fi[N],se,col[N],dis[N],que[N],s,t;
inline void add_edge(int u,int v,int w){edge[++se]={fi[u],v,w},fi[u]=se;}
inline void add(int u,int v,int w){add_edge(u,v,w),add_edge(v,u,w);} 
int main(){
	int n,m,u,v,w;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d%d",&u,&v,&w),add_edge(v,u,w);
	for(int i=1;i<=n;i++)col[i]=-1;
	que[t++]=n;dis[n]=1;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;if(dis[v])continue;
			if(col[v]==-1)col[v]=edge[i].w^1;
			else if(col[v]==edge[i].w){
				que[t++]=v;dis[v]=dis[u]+1;
			}
		}
	}
	printf("%d\n",dis[1]?dis[1]-1:-1);
	for(int i=1;i<=n;i++)putchar(col[i]==1?'1':'0');
	return 0;
}
