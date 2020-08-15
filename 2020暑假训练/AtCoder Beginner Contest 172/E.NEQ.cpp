#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7,N=5e5+5;
void Inverse(int p,int a[],int n){//线性求<=n的数%p意义下的逆元 
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int inv[N],fac[N];
void init(int n){
	fac[0]=inv[0]=1;Inverse(mo,inv,n);
	for(int i=1;i<=n;i++)inv[i]=1ll*inv[i-1]*inv[i]%mo,fac[i]=1ll*i*fac[i-1]%mo;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
int P(int n,int m){return 1ll*fac[n]*inv[n-m]%mo;}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	init(max(n,m));
	long long ans=0;
	for(int i=0;i<=n;i++)
		(ans+=(i&1?-1ll:1ll)*P(m,i)*C(n,i)%mo*P(m-i,n-i)%mo*P(m-i,n-i)%mo)%=mo;
	printf("%d",(ans+mo)%mo);
	return 0;
}
