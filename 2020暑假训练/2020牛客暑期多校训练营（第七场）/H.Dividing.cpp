#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mo=1e9+7,inv=5e8+4;
LL work(LL n,LL k){
	LL n1,ans=0;n1=sqrt(n);
	for(int i=1;i<=k&&n/i>n1;i++){
		(ans+=(n/i))%=mo;
	}
	for(LL i=max(1ll,n/k);i<=n1;i++){
		LL l=n/(i+1)+1,r=min(n/i,k);
		(ans+=i*(r-l+1)%mo)%=mo;
	}
	return ans;
} 
int main(){
	LL w,k;scanf("%lld%lld",&w,&k);
	printf("%d\n",((work(w,k)+work(w-1,k)-w+k)%mo+mo)%mo);
}
