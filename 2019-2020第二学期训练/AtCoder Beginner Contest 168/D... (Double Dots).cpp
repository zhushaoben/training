#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Edge{
	int next,to;
}edge[N*2];
int fi[N],se,pre[N],que[N],s,t;
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v);
	que[t++]=1;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;if(pre[v])continue;
			pre[v]=u,que[t++]=v;
		}
	}
	if(s<n)return puts("No"),0;
	puts("Yes");for(int i=2;i<=n;i++)printf("%d\n",pre[i]);
	return 0;
}
