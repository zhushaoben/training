#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL n,m,mi,ma;scanf("%lld%lld",&n,&m);
	mi=max(0ll,n-m*2);
	for(int i=1;i<=n;i++){
		if(m<=1ll*i*(i-1)/2){ma=n-i;break;}
	}
	if(!m)ma=n;
	printf("%lld %lld",mi,ma);
	return 0;
}
