/*
first we have a guess,we ergodic each node 
if its number of edges less than remain nodes 
then it can be connected with at least one nodes remain,we will add ans on that node
else ans++
then we delete all its edges

but the thinking have one leak,a node may not connected with all the node
after delete some nodes,we think it was connected with all the node,
(it can be connected by some 0 weight edges to those nodes it have 1 weight edge connected with)
then the answer will be larger

so each time er take the node who have the most edges present
then we do the steps writed above
think that if a node connect with all nodes after we delete the present node
and it can be connected by some 0 weight edges through present edge
then that the number of its edges must more than the present's
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
