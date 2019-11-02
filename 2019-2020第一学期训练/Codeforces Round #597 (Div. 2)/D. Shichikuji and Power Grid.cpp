#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
#define LL long long
struct Edge{
	LL c;int u,v;
	bool operator < (const Edge &b)const{
		return c<b.c;
	}
}edge[maxn*maxn];
int se,x[maxn],y[maxn],c[maxn],k[maxn],fa[maxn],ans1[maxn],s1,s2;
struct A{
	int u,v;
}ans2[maxn];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main(){
	int n;scanf("%d",&n);LL ans=0;
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i),fa[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",c+i),edge[se++]={c[i],i,n+1};
	for(int i=1;i<=n;i++)scanf("%d",k+i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			edge[se++]={1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),i,j};
		}
	}
	sort(edge,edge+se);
	for(int i=0;i<se;i++){
		int u=Find(edge[i].u),v=Find(edge[i].v);
		if(u!=v){
			fa[v]=u,ans+=edge[i].c;
			if(edge[i].v==n+1){ans1[s1++]=edge[i].u;}
			else{ans2[s2++]={edge[i].u,edge[i].v};}
		}
	}
	printf("%lld\n%d\n",ans,s1);
	for(int i=0;i<s1;i++)printf("%d ",ans1[i]);printf("\n%d\n",s2);
	for(int i=0;i<s2;i++)printf("%d %d\n",ans2[i].u,ans2[i].v);
	return 0;
}
