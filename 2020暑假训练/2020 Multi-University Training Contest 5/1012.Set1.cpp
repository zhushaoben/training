#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=5e6+5,Inv=499122177; 
void Inverse(int p,int a[],int n){
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int inv[N],fac[N],p[N];
void init(int n){
	p[0]=fac[0]=inv[0]=1;Inverse(mo,inv,n);
	for(int i=1;i<=n;i++)p[i]=1ll*p[i-1]*Inv%mo,inv[i]=1ll*inv[i-1]*inv[i]%mo,fac[i]=1ll*i*fac[i-1]%mo;
}
int C(int n,int m){if(n<m)return 0;return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
void work(){
	int n,n1;scanf("%d",&n),n1=n/2;
	for(int i=0;i<n-1;i++){
		printf("%d ",1ll*C(i,n1)*p[i]%mo);
	}
	printf("%d\n",n==1?1:1ll*C(n-2,n1)*p[n-2]%mo);
}
int main(){
//	freopen("1.in","w",stdout);
	int t;scanf("%d",&t);
	init(5e6+1);
	while(t--)work(); 
	return 0;
}
