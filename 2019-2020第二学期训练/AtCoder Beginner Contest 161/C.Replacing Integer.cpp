#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;scanf("%lld%lld",&n,&k);
	n%=k;
	printf("%lld",min(n,k-n));
	return 0;
}
