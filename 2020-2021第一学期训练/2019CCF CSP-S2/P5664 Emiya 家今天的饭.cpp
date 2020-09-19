#include<bits/stdc++.h>
using namespace std;
const int N=105,M=2005,mo=998244353;
int a[N][M],s[N],f[N];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",a[i]+j),(s[i]+=a[i][j])%=mo;
	int ans=1;
	for(int i=1;i<=n;i++)ans=1ll*ans*s[i]%mo;
	for(int i=1;i<=m;i++){
		memset(f,0,(n+1)<<2);f[0]=1;
		for(int j=1;j<=n;j++){
			for(int k=j;k;k--)
				f[k]=(1ll*f[k-1]*a[j][i]+1ll*f[k]*(s[j]-a[j][i]))%mo;
			f[0]=1ll*f[0]*(s[j]-a[j][i])%mo;
		}	
		for(int j=n/2+1;j<=n;j++)(ans-=f[j])%=mo;
	}
	printf("%d",(ans+mo)%mo);
	return 0;
}
