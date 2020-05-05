#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define mo 998244353
int f[maxn][maxn*2][4],w1[4][4]={
	{0,1,1,1},
	{0,0,2,0},
	{0,2,0,0},
	{1,1,1,0}
};
int main(){
	int n,k;scanf("%d%d",&n,&k);
	f[1][1][3]=f[1][1][0]=1;f[1][2][1]=f[1][2][2]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			for(int k=0;k<4;k++){
				for(int l=0;l<4;l++){
					int w=w1[k][l];
					(f[i+1][j+w][l]+=f[i][j][k])%=mo;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<4;i++)(ans+=f[n][k][i])%=mo;
	printf("%d",ans);
	return 0;
}
