#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
struct Edge{
	int next,to;
}edge[maxn*4];
int a[maxn],ans[maxn],que[maxn*2],s,t,fi[maxn],se;
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
void bfs(){
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;if(ans[v])continue;
			ans[v]=ans[u]+1;que[t++]=v;
		}
	}
}
int main(){
	int n,x;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		x=i-a[i];if(x>0){
			if((a[x]&1)^(a[i]&1))ans[i]=1,que[t++]=i;
			else add_edge(x,i);
		}
		x=i+a[i];if(x<=n){
			if((a[x]&1)^(a[i]&1))ans[i]=1,que[t++]=i;
			else add_edge(x,i);
		}
	}
	bfs();
	for(int i=1;i<=n;i++)printf("%d ",ans[i]?ans[i]:-1);
	return 0;
}
