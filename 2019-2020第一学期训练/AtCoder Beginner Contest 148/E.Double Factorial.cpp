#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL n,ans=0;scanf("%lld",&n);
	if(n&1)return putchar('0'),0;
	n/=2;while(n)n/=5,ans+=n;
	printf("%lld",ans);
	return 0;
}
