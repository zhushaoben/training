#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mo=1e9+7;
void Inverse(int a[],int n){
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(mo-mo/i)*a[mo%i]%mo;
	}
}
int s[N],inv[N],fac[N];
int main(){
	Inverse(inv,5e4);
	fac[1]=fac[0]=1;for(int i=2;i<5e4;i++)s[i]=i+s[i-1],fac[i]=1ll*i*fac[i-1]%mo;
	int t,x,n,w=5e4;scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		if(x==1){puts("1");continue;}
		n=upper_bound(s+2,s+w,x)-s-1;
		x-=s[n];
		if(x==n)printf("%d\n",1ll*fac[n+2]*inv[2]%mo*inv[n+1]%mo);
		else printf("%d\n",1ll*fac[n+1]*inv[n+1-x]%mo);
	}
	return 0;
}
