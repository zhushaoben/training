#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],fa[N*2];
struct Edge{
	int u,v,w;
	bool operator < (const Edge &b)const{return w>b.w;}
}e[N*2];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main(){
	int m,n,s,x;scanf("%d%d",&m,&n);
	for(int i=n+m;i;i--)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	int si=0;long long ans=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&s);
		for(int j=0;j<s;j++){
			scanf("%d",&x);
			e[si++]={i,x+m,a[i]+b[x]};
			ans+=a[i]+b[x];
		}
	}
	sort(e,e+si);
	for(int i=0;i<si;i++){
		int u=Find(e[i].u),v=Find(e[i].v);
		if(u!=v)fa[u]=v,ans-=e[i].w;
	}
	printf("%lld",ans);
	return 0;
}
