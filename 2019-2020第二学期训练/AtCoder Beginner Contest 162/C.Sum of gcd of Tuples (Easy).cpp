#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e2+5,mo=1e9+7;
LL Power(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int f[N];
int main(){
	int n=3,k;scanf("%d",&k);
	LL ans=0;
	for(int i=k;i;i--){
		f[i]=Power(k/i,n);
		for(int j=i*2;j<=k;j+=i)(f[i]-=f[j])%=mo;
		ans+=1ll*i*f[i]%mo;
	}
	printf("%lld",(ans%mo+mo)%mo);
	return 0;
}
