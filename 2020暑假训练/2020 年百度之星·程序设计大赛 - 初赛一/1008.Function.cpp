#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mo=1e9+7;
LL calc(LL l,LL r,LL d){
	return (l+r)%mo*((r-l)/d%mo+1)%mo;
}
void work(){
	LL n,n1,ans;scanf("%lld",&n),n1=sqrt(n);
	ans=n%mo*(n%mo)%mo+n;
	for(int i=1;i<=n1;i++){
		(ans+=(n/i)%i-(n/i))%=mo;
		(ans-=calc(n%(n/i),n%(n/(i+1)+1),i))%=mo;
	}
	printf("%lld\n",(ans+mo)%mo);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
