#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int fa[maxn+5];
int Find(int x){
	return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);
}
int main(){
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++){scanf("%d%d",&u,&v),u=Find(u),v=Find(v);if(u>v)fa[u]=v;else fa[v]=u;}
	int ans=0,pre=n+1;
	for(int i=n;i;i--){
		int u=Find(i);
		if(pre<i&&u!=pre){if(u>pre)fa[u]=pre;else fa[pre]=u;ans++;}
		pre=fa[u];
	}
	printf("%d",ans);
	return 0;
} 
