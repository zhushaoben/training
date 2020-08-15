#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
struct Edge{
	int next,to,w;
}edge[N*2];
struct Node{
	long long a,b;
	bool operator <(const Node &c)const{
		if((b>=0)^(c.b>=0))return b>=0;
		if(b>=0)return a<c.a;
		else return a+b>c.a+c.b; 
	}
}f[N],st[N];
int fi[N],se,top,a[N];
inline void add_edge(int u,int v,int w){edge[++se]={fi[u],v,w},fi[u]=se;}
inline void add(int u,int v,int w){add_edge(u,v,w),add_edge(v,u,w);}
void dfs(int x,int fa){
	int t=top;f[x].b=a[x];
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);
		st[top]={max(f[v].a+edge[i].w,-f[v].b+edge[i].w*2),f[v].b-edge[i].w*2};
		f[x].b+=st[top++].b;
	}
	sort(st+t,st+top);
	long long w=a[x],ans=0;
	for(int i=t;i<top;i++){
		if(w<st[i].a)ans+=st[i].a-w,w=st[i].a;
		w+=st[i].b;
	}
	f[x].a=ans;
	top=t;
}
void work(){
	int n,u,v,w;scanf("%d",&n);
	memset(fi,0,sizeof(int)*(n+5)),se=top=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++)scanf("%d%d%d",&u,&v,&w),add(u,v,w);
	dfs(1,0);
	printf("%lld\n",f[1].a);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
