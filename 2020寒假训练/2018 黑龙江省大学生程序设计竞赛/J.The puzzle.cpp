#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];bool vis[maxn];
void dfs(int x){
	while(!vis[x]){
		vis[x]=1;x=a[x];
	}
}
void work(){
	int n,ans;scanf("%d",&n),ans=n;
	for(int i=1;i<=n;i++)scanf("%d",a+i),vis[i]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i])ans--,dfs(i);
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
