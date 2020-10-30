#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
typedef long long LL;
LL calc(LL x){if(x<=0)return 0;return (x+1)*x;}
void work(){
	LL n,a,b,w,w1;scanf("%lld%lld%lld",&n,&a,&b);
	w=(n-a+1)*(n-b+1),w1=w-calc(n-a-b+1);
	w%=mo,w1%=mo;
	printf("%d\n",(w*w%mo-w1*w1%mo+mo)%mo);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
