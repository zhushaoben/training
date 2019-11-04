#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=1e5+10;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct Edge{
	int next,to;
}edge[N*2];
int fi[N*2],se,num[N*2],siz,a[N],b[N],ans,ans1[N],ans2[N];
bool vis[N*2];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,
	edge[++se].next=fi[v],fi[v]=se,edge[se].to=u;
}
void dfs(int x,int fa){
	vis[x]=1;
	if(!edge[fi[x]].next)ans1[ans]=fi[x]/2,ans2[ans]=x;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		if(vis[v]){ans1[ans]=i/2,ans2[ans]=edge[i].to;continue;}
		dfs(v,x);
	}
}
void work(){
	int n=read();se=1,siz=0;
	for(int i=1;i<=n;i++){
		a[i]=read(); b[i]=read();
		num[++siz]=a[i]; num[++siz]=b[i];
	}
	sort(num+1, num+2*n+1);
	siz=unique(num+1, num+2*n+1)-num-1;
	memset(fi,0,sizeof(int)*(siz+5));memset(vis,0,sizeof(bool)*(siz+5));
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(num+1, num+siz+1,a[i])-num;
		b[i]=lower_bound(num+1, num+siz+1,b[i])-num;
		add_edge(a[i],b[i]);
	}
	ans=-1;
	for(int i=1;i<=siz;i++){
		if(!vis[i])ans++,dfs(i,0);
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
		printf("%d %d %d\n",ans1[i],num[ans2[i]],num[1]);
	}
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}
