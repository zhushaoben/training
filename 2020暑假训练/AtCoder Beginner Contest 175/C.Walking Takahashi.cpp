#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL x,k,d;scanf("%lld%lld%lld",&x,&k,&d);
	x=abs(x);
	if(x/d>=k)return printf("%lld",x-d*k),0;
	k-=x/d,x%=d;
	if(k&1)printf("%lld",d-x);
	else printf("%lld",x);
	return 0;
}
