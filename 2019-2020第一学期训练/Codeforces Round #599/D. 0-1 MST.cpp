/*
for this problem we should find the minimum spanning tree for the given graph

we define d[v] indicates the number of edges connecting v weighted 1

first we have a speculation that  we iterate over all vertices v from 1 to n
if d[v] less than the number of remain nodes 
then it can be connected with at least one nodes by edges weight 0,
we can delete this node and all edges connecting it

else ans++ ,we delete it and all its edges

but the thinking have one leak,
when we delete the node v,there may be a node u that d[u]=the number of remain nodes
but if we delete u earlier,the answer will be less

so each time we delete the node whose d[] is the biggest
then the situation will only appear when d[v]=the number of remain nodes-1;
for tis situation the answer is right
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
struct Edge{
	int next,to;
}edge[maxn*2+5];
int fi[maxn+5],se,d[maxn+5];
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u),d[u]++,d[v]++;}
priority_queue<pair<int,int> >q;
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v);
	for(int i=1;i<=n;i++)q.push(pair<int,int>{d[i],i});
	int remain=n,ans=0;
	while(!q.empty()){
		if(remain<=1)break;
		int u=q.top().second,w=q.top().first;q.pop();
		if(d[u]!=w)continue;remain--;
		if(d[u]==remain)ans++;d[u]=0;
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(d[v])q.push(pair<int,int>{--d[v],v});
		}
	}
	printf("%d",ans);
	return 0;
}
