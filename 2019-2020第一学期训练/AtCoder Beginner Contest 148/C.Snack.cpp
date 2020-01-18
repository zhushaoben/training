#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int main(){
	LL a,b;scanf("%lld%lld",&a,&b);
	printf("%lld",a*b/gcd(a,b));
	return 0;
}
