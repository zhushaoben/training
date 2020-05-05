#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define mo 998244353
long long f[maxn][maxn];int c[maxn][maxn];char s[maxn],t[maxn];
void work(){
	int n,k,m,st=0;scanf("%d%d%d%s%s",&n,&k,&m,s,t),memset(f,0,sizeof(f));
	for(int i=0;s[i];i++)st+=(s[i]!=t[i]);
	f[0][st]=1;
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=min(j,m);k++){
				(f[i+1][j+m-2*k]+=f[i][j]*c[j][k]%mo*c[n-j][m-k])%=mo;
			}
		}
	}
	printf("%d\n",f[k][0]);
}
int main(){
	c[0][0]=1;
	for(int i=1;i<=100;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
