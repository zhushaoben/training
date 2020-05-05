#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int h[N];bool vis[N];
int main(){
	int u,v,n,m,ans=0;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",h+i);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		if(h[u]<=h[v])vis[u]=1;
		if(h[v]<=h[u])vis[v]=1;
	}
	for(int i=1;i<=n;i++)if(!vis[i])ans++;
	printf("%d",ans);
	return 0;
}
