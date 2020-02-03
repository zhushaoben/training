#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(){
	int n,c,x;scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		for(int j=0;j<=c;j++){
			if(j==x)continue;
			dp[j][x]=max(dp[j][x],dp[x][j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=c;i++)for(int j=1;j<=c;j++)ans=max(ans,dp[i][j]);
	if(ans==1)ans=0;
	printf("%d",ans);
	return 0;
}
