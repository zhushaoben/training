#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
struct Edge{
	int next,to,w;
}edge[N<<1];
struct Node{
	LL a,b;
	bool operator <(const Node &c)const{
		if(a!=c.a)return a<c.a;
		return b<c.b;
	}
}que[N],f[N];
int n,k,fi[N],se,top;
inline void add_edge(int u,int v,int w){edge[++se]={fi[u],v,w},fi[u]=se;}
inline void add(int u,int v,int w){add_edge(u,v,w),add_edge(v,u,w);}
LL ans,d1[N];
void dfs(int x,int fa){
	int t=top;f[x]={0,0};
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);que[top++]={f[v].a+edge[i].w,f[v].b+edge[i].w};
	}
	sort(que+t,que+top);
//	if(!fa)k++;
	if(top-t<k){
		LL w=0,ma=0;
		for(int i=t;i<top;i++)
			w+=que[i].a,ma=max(que[i].b-que[i].a,ma);
		f[x]={w,w+ma};
	}
	else{
		LL w=0,ma=0,w1;int j=top-k+1;
		for(int i=j;i<top;i++)w+=que[i].a,ma=max(que[i].b-que[i].a,ma);w1=w;
		for(int i=j-1;i>=t;i--)ma=max(que[i].b-que[j].a,ma),w1+=que[i].a;
		f[x]={w,max(w1,w+ma)};
	}
	k++;
	if(top-t<k){
		LL w=0,ma=0;
		for(int i=t;i<top;i++)
			w+=que[i].a,ma=max(que[i].b-que[i].a,ma);
		ans=max(ans,w+ma);
	}
	else{
		LL w=0,ma=0,w1;int j=top-k+1;
		for(int i=j;i<top;i++)w+=que[i].a,ma=max(que[i].b-que[i].a,ma);w1=w;
		for(int i=j-1;i>=t;i--)ma=max(que[i].b-que[j].a,ma),w1+=que[i].a;
		ans=max(ans,max(w1,w+ma));
	}
	k--;
	ans=max(ans,max(f[x].a,f[x].b));
	top=t;
}
void work(){
	scanf("%d%d",&n,&k);
	memset(fi,0,sizeof(int)*(n+2)),se=0,ans=0,top=0;
	memset(d1,0,sizeof(LL)*(n+2));
	int u,v,w; 
	for(int i=1;i<n;i++)scanf("%d%d%d",&u,&v,&w),add(u,v,w),d1[u]+=w,d1[v]+=w;
	if(k==0){puts("0");return;}
	if(k==1){
		for(int i=1;i<=n;i++)ans=max(ans,d1[i]);
		printf("%lld\n",ans);return;
	}
	dfs(1,0);
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
/*
2
5 5
1 2 5
2 3 2
2 4 3
2 5 4

6 2
1 2 5
1 6 5
2 3 2
2 4 3
2 5 4
*/
