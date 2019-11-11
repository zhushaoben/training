#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
int main(){
	LL n,ans;scanf("%lld",&n),ans=n;
	for(LL i=2;i*i<=n;i++){
		if(n%i==0){ans=gcd(ans,i);while(n%i==0)n/=i;}
	}
	if(n>1)ans=gcd(ans,n);
	printf("%lld",ans);
	return 0;
}
