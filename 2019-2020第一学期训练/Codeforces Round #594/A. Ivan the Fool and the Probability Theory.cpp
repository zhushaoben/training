#include<bits/stdc++.h>
#define mo 1000000007
#define LL long long
#define maxn 100000
using namespace std;
int fac[maxn+5],inv[maxn+5];
int C(int m,int n){
	return 1ll*fac[m]*inv[n]%mo*inv[m-n]%mo;
}
int main(){
	fac[1]=inv[1]=inv[0]=fac[0]=1;
	for(int i=2;i<=maxn;i++){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	}
	for(int i=2;i<=maxn;i++)inv[i]=1ll*inv[i]*inv[i-1]%mo;
	int n,m;scanf("%d%d",&n,&m);
	LL ans=1;
	for(int i=1;i<=n/2;i++){
		(ans+=C(n-i,i))%=mo;
	}
	for(int i=1;i<=m/2;i++){
		(ans+=C(m-i,i))%=mo;
	}
	printf("%d\n",ans*2%mo);
	return 0;
} 
