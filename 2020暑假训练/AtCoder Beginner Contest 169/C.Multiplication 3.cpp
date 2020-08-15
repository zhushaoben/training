#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL a,b,x;scanf("%lld%lld.%lld",&a,&b,&x);
	b=b*100+x;
	printf("%lld\n",a*b/100);
	return 0;
}
