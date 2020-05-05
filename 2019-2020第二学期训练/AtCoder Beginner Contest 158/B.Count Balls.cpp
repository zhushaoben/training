#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n,a,b;scanf("%lld%lld%lld",&n,&a,&b);b+=a; 
	printf("%lld",n/b*a+min(n%b,a));
	return 0;
}
