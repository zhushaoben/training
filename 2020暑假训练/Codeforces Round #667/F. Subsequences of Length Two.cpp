#include<bits/stdc++.h>
using namespace std;
char s[205],t[10];
int f[205][205][205];
int main(){
	int n,k;scanf("%d%d%s%s",&n,&k,s+1,t);
	memset(f,0x8f,sizeof(f));
	f[0][0][0]=0;
	for(int i=1;s[i];i++){
		for(int j=0;j<=i&&j<=k;j++){
			for(int k=0;k<=i;k++){
				f[i][j][k+(s[i]==t[0])]=max(f[i-1][j][k]+(s[i]==t[1]?k:0),f[i][j][k+(s[i]==t[0])]);
				f[i][j+1][k+1]=max(f[i][j+1][k+1],f[i-1][j][k]+(t[0]==t[1]?k:0));
				f[i][j+1][k]=max(f[i][j+1][k],f[i-1][j][k]+k);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++)for(int j=1;j<=n;j++)ans=max(ans,f[n][i][j]);
	printf("%d",ans);
	return 0;
}
