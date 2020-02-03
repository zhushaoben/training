#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
struct Edge{
	int next,to,a,b;
}edge[maxn*2];
int fi[maxn],se;LL le[maxn];
bool vis[maxn];
inline void add_edge(int u,int v,int a,int b){edge[++se].next=fi[u],edge[se].to=v,edge[se].a=a,edge[se].b=b,fi[u]=se;}
int log(LL x){
	int ans=0;
	while(x)x>>=1,ans++;
	return ans-1;
}
priority_queue<pair<LL,int> > q;
bool check(LL x,int a,int b){
	return (x+a)/x>=(1ll<<b);
}
void dijk(){
	le[1]=1;
	q.push(make_pair(-1,1));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;vis[u]=1;
        for(int i=fi[u];i;i=edge[i].next){
        	int v=edge[i].to;
        	if((!le[v]||le[v]>le[u]+edge[i].a)&&check(le[u],edge[i].a,edge[i].b)){
        		le[v]=le[u]+edge[i].a;
        		q.push(make_pair(-le[v],v));
			}
		}
    }
}
void work(){
	int n,m,u,v,a,b;scanf("%d%d",&n,&m);
	memset(vis,0,sizeof(vis)),memset(fi,0,sizeof(fi)),se=0,memset(le,0,sizeof(le));
	for(int i=0;i<m;i++)scanf("%d%d%d%d",&u,&v,&a,&b),add_edge(u,v,a,b);
	dijk();
	printf("%d\n",log(le[n]));
} 
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
