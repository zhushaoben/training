#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,mo=1e9+7;
typedef long long LL;
char s[N];
void Inverse(int p,int a[],int n){//线性求<=n的数%p意义下的逆元 
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int inv[N],fac[N],pow25[N],pow26[N];
void init(int n){
	pow25[0]=pow26[0]=fac[0]=inv[0]=1;Inverse(mo,inv,n);
	for(int i=1;i<=n;i++)inv[i]=1ll*inv[i-1]*inv[i]%mo,fac[i]=1ll*i*fac[i-1]%mo,pow25[i]=25ll*pow25[i-1]%mo,pow26[i]=26ll*pow26[i-1]%mo;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
int main(){
	int k,l;scanf("%d%s",&k,s),l=strlen(s);
	LL ans=0;
	init(k+l);
	for(int i=0;i<=k;i++){
		(ans+=1ll*pow26[k-i]*pow25[i]%mo*C(l+i-1,i)%mo)%=mo;
	}
	printf("%d",ans);
	return 0;
}
