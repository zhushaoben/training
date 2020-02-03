#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
LL phi(LL x){
    LL ans = x;
    for(LL i=2; i*i<=x;i++){
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ans=ans/x*(x-1);
    return ans;
}
void work(){
	LL a,m;scanf("%lld%lld",&a,&m);
	m/=gcd(a,m);
	printf("%lld\n",phi(m));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
