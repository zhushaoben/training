#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL n,ans;scanf("%lld",&n);
	int n1=sqrt(n);
	for(int i=1;i<=n1;i++){
		if(n%i==0)ans=i+n/i;
	}
	printf("%lld\n",ans-2);
	return 0;
}
