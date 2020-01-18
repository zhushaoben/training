#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct Edge{
	int next,to,w;
}edge[maxn*2],e[maxn];
int fi[maxn],se,lay[maxn],head[maxn],n,m,c,si,dis[maxn];
bool vis[maxn],s[maxn];
inline void add_edge(int u,int v,int w){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,edge[se].w=w;}
inline void add(int u,int v,int w){add_edge(u,v,w),add_edge(v,u,w);}
inline void insert(int i,int x){e[++si].next=head[i],head[i]=si,e[si].to=x;}
priority_queue<pair<int,int> >q;
void dijkstra(){
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int u=q.top().second,w=lay[u];q.pop();
        if(s[u])continue;s[u]=1;
        if(!vis[w-1]){
        	vis[w-1]=1;
        	for(int i=head[w-1];i;i=e[i].next){
        		int v=e[i].to;
        		if(dis[v]>dis[u]+c){
        			dis[v]=dis[u]+c;
        			q.push(make_pair(-dis[v],v));
				}
			}
		}
		if(!vis[w+1]){
			vis[w+1]=1;
			for(int i=head[w+1];i;i=e[i].next){
        		int v=e[i].to;
        		if(dis[v]>dis[u]+c){
        			dis[v]=dis[u]+c;
        			q.push(make_pair(-dis[v],v));
				}
			}
		}
        for(int i=fi[u];i;i=edge[i].next){
        	int v=edge[i].to;
        	if(dis[v]>dis[u]+edge[i].w){
        		dis[v]=dis[u]+edge[i].w;
        		q.push(make_pair(-dis[v],v));
			}
		}
    }
}
void work(){
	int u,v,w;
	scanf("%d%d%d",&n,&m,&c);
	si=se=0,memset(fi,0,sizeof(int)*2*n+5),memset(head,0,sizeof(int)*n*2+5);
	for(int i=1;i<=n;i++)scanf("%d",lay+i),insert(lay[i],i);
	for(int i=0;i<m;i++)scanf("%d%d%d",&u,&v,&w),add(u,v,w);
	for(int i=1;i<=n;i++)vis[i]=0,s[i]=0,dis[i]=1e9;
	dijkstra();
	printf("%d\n",dis[n]==1e9?-1:dis[n]);
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
