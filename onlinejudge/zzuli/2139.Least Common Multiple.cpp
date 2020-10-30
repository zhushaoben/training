#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mo=1e9+7;
LL qpow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%mo;
		a=a*a%mo,b>>=1;
	}
	return ans;
}
LL a[20];
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void work(){
	int n,s;scanf("%d",&n),s=(1<<n);
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	LL ans=1;
	for(int i=1;i<s;i++){
		LL g=0;int w=0;
		for(int j=0;j<n;j++)if(i&(1<<j))w++,g=gcd(a[j],g);
		if(!(w&1))ans=ans*qpow(g%mo,mo-2)%mo;
		else ans=ans*(g%mo)%mo;
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
