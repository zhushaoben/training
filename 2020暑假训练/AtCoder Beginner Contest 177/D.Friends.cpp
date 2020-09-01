#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int fa[N],w[N];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		u=Find(u),v=Find(v);
		fa[u]=v;
	}
	for(int i=1;i<=n;i++)w[Find(i)]++;
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,w[i]);
	printf("%d",ans);
	return 0;
}
