#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,n;scanf("%lld%lld%lld",&a,&b,&n);
	printf("%lld",a*min(b-1,n)/b);
	return 0;
}
