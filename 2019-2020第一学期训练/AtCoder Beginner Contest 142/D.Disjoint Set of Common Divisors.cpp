#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
int main(){
	LL a,b,c;int ans=1;
	scanf("%lld%lld",&a,&b);c=gcd(a,b);
	for(LL i=2;i*i<=c;i++){
		if(c%i==0)ans++;
		while(c%i==0)c/=i;
	}
	printf("%d",ans+(c>1));
	return 0;
}
