#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=2e5+5; 
typedef long long LL; 
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
int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	init(n);
	LL w=1,ans=0;
	for(int i=0;i<n-1-k;i++)(w*=m-1)%=mo;
	for(int i=k;i>=0;i--)
		ans+=w*C(n-1,i)%mo*m%mo,(w*=m-1)%=mo;
	printf("%d",ans%mo);
	return 0;
}
