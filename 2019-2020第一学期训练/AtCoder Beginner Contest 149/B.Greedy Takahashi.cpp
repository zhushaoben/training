#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL a,b,k;scanf("%lld%lld%lld",&a,&b,&k);
	printf("%lld %lld",max(0ll,a-k),max(0ll,min(b,b+a-k)));
	return 0;
}
