#include<bits/stdc++.h>
using namespace std;
const int N=205;
char s[N],t[N];
long long f[N][N];
int main(){
	int q,n,d;scanf("%d%d%d%s%s",&q,&n,&d,s+1,t+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]==t[i])for(int j=0;j<=d;j++)f[i][j]+=f[i-1][j],f[i][j+2]+=(q-1)*f[i-1][j];
		else for(int j=0;j<=d;j++)f[i][j+1]+=f[i-1][j]*2,f[i][j+2]+=(q-2)*f[i-1][j];
	}
	printf("%lld",f[n][d]);
	return 0;
}
