#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL ans=0,a,b,x,d=1;scanf("%lld%lld%lld",&a,&b,&x);
	for(int i=1;i<=10;i++,d*=10){
		if(d*a+b*i>x)break;
		ans=min((x-b*i)/a,d*10-1);
	}
	ans=min(ans,1000000000ll);
	printf("%lld",ans);
	return 0;
}
