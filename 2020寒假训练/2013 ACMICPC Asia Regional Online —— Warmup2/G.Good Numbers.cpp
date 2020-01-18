#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL calc(LL x){
	if(x<0)return 0;
	LL x1=x,w=0,d=x%10;
	while(x1)w+=x1%10,x1/=10;
	return x/10+(w%10<=d);
}
void work(){
	LL l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",calc(r)-calc(l-1));
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
