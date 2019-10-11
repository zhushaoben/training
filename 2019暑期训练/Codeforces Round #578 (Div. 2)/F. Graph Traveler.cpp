#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define ll long long
int K[maxn],m[maxn],ans[maxn][5400];
ll vis[maxn][5400],t;
vector<int> v[maxn];
int dfs(int x,int k){
	if(ans[x][k])return ans[x][k];
	if(vis[x][k]/200000000ll==t/200000000ll)return ans[x][k]=t%200000000-vis[x][k]%200000000;
	vis[x][k]=++t;
	return ans[x][k]=dfs(v[x][k%m[x]],(k+K[x])%5400);
}
int main(){
	int n,x;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",K+i);
	for(int i=1;i<=n;i++){
		scanf("%d",m+i);
		for(int j=0;j<m[i];j++){
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<5400;j++)t=i*2000000000ll+j*200000000ll,dfs(i,j);
	}
	int q;scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		y=((y%5400)+5400)%5400;
		printf("%d\n",ans[x][y]);
	}
	return 0;
}
