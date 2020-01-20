#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define mo 1000000007
int a[maxn],fac[maxn],inv[maxn];
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
inline int C(int n,int m){return m>n?0:1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
int main(){
	int n,k,ans=0;scanf("%d%d",&n,&k);
	fac[0]=1;for(int i=0;i<n;i++)scanf("%d",a+i),fac[i+1]=1ll*fac[i]*(i+1)%mo;
	inv[n]=Pow(fac[n],mo-2);sort(a,a+n);
	for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mo;
	for(int i=0;i<n;i++){
		(ans+=1ll*a[i]*(C(i,k-1)-C(n-i-1,k-1))%mo)%=mo;
	}
	printf("%d",(ans+mo)%mo);
	return 0;
}
