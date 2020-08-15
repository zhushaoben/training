#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=998244353;
int inv[N],fac[N];
int C(int n,int m){return 1ll*fac[n]*inv[n-m]%mo*inv[m]%mo;}
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1; 
	}
	return ans;
}
int main(){
	int n,k,x,d=1,ans=0;scanf("%d%d",&n,&k);
	if(k>=n)return puts("0"),0;
	inv[0]=inv[1]=1,fac[0]=1;
	for(int i=2;i<=n;i++)inv[i]=(-1ll*(mo/i)*inv[mo%i]%mo+mo)%mo;
	for(int i=1;i<=n;i++)inv[i]=1ll*inv[i]*inv[i-1]%mo,fac[i]=1ll*i*fac[i-1]%mo;
	x=n-k;
	for(int i=0;i<x;i++)
		(ans+=1ll*d*C(x,x-i)*Pow(x-i,n)%mo)%=mo,d=-d;
	ans=(ans+mo)%mo;
	printf("%d\n",(k?2ll:1ll)*ans*C(n,k)%mo);
	return 0;
} 
