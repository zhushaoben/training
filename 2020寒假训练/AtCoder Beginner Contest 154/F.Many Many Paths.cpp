#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,mo=1e9+7;
void Inverse(int p,int a[],int n){//线性求<=n的数%p意义下的逆元 
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int inv[N],fac[N];
int C(int n,int m){
	return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int main(){
	int a,b,c,d;scanf("%d%d%d%d",&a,&c,&b,&d);
	Inverse(mo,inv,1e6+2);
	fac[0]=inv[0]=1;for(int i=1;i<=2000002;i++)fac[i]=1ll*fac[i-1]*i%mo,inv[i]=1ll*inv[i]*inv[i-1]%mo;
	int ans=0,sum=0;
	for(int i=a;i<=b;i++)
		(ans+=C(d+i+1,i+1)-C(i+c,i+1))%=mo;//朱世杰恒等式
	printf("%d",(ans+mo)%mo);
	return 0;
}
