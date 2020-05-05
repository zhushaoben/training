#include<bits/stdc++.h>
using namespace std;
bool vis[105];
int main(){
	int n,k,d,x,ans=0;scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		scanf("%d",&d);
		for(int j=0;j<d;j++)scanf("%d",&x),vis[x]=1;
	}
	for(int i=1;i<=n;i++)if(!vis[i])ans++;
	printf("%d",ans);
	return 0;
}
