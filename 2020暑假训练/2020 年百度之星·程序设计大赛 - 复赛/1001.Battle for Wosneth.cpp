#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
long long qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
void work(){
	long long m,p,q;scanf("%lld%lld%lld",&m,&p,&q);
	printf("%d\n",((m-(1ll*m*qpow(p,mo-2)%mo-qpow(100,mo-2))*q%mo)%mo+mo)%mo);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
