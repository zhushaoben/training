#include<bits/stdc++.h>
using namespace std;
#define LL long long
void work(){
	LL n,a,b,ans,n1;scanf("%lld%lld%lld",&n,&a,&b);
	n1=(n+1)/2;ans=((n1-1)/a)*(a+b)+(n1-1)%a+1;
	printf("%lld\n",max(n,ans));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
