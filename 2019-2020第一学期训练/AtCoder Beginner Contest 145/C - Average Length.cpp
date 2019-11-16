#include<bits/stdc++.h>
using namespace std;
long double ans,w;
int x[10],y[10],vis[10],n;
long double dis(int u,int v){
	return v!=-1?sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v])):0;
}
void dfs(int x,int pre){
	if(!x){ans+=w;return;}
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		vis[i]=1,w+=dis(i,pre);
		dfs(x-1,i);
		vis[i]=0,w-=dis(i,pre);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
	dfs(n,-1);
	for(int i=2;i<=n;i++)ans/=i;
	printf("%.10Lf",ans);
	return 0;
}
