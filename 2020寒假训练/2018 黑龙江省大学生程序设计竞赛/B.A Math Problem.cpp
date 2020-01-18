#include<bits/stdc++.h>
using namespace std;
#define LL long long
void work(){
	unsigned LL ans=1;
	LL n;scanf("%lld",&n);
	for(LL i=1;i<2*n;i+=2)ans*=i;
	printf("%llu\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
