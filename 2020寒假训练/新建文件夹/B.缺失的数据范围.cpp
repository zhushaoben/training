#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a,b,k;
LL log(LL n){
	LL i=0,ans=1;
	while(ans<n)ans<<=1,i++;
	return i;
}
bool check(LL x){
	LL ans=1,ans1=1;
	for(int i=0;i<a;i++)ans*=x;
	for(int i=0;i<b;i++)ans1*=log(x);
	return k/ans>=ans1;
}
void work(){
	scanf("%lld%lld%lld",&a,&b,&k);
	LL l=0,r=pow(k,1.0/a)+10,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",r);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
