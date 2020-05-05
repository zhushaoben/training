#include<bits/stdc++.h>
using namespace std;
#define maxn 2505
int dis[maxn][maxn],vis[maxn];
vector<int>v[10000001];
int main(){
	int n,num=1;scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)scanf("%d",dis[i]+j);
		for(int j=0;j<i;j++)v[dis[i][j]].push_back(i*n+j);
	}
	for(int i=10000000;i;i--){
		for(auto j:v[i]){
			int u=j/n,v=j%n,mi=1e7+1,w;
			if(vis[u]||vis[v])continue;
			for(int k=0;k<n;k++)if(!vis[k]&&dis[u][k]&&dis[u][k]<mi)mi=dis[u][k],w=k;
			printf("%d %d\n",u+1,w+1);vis[u]=1,num++;
			if(num==n)break;
		}
		if(num==n)break;
	}
	return 0;
}
