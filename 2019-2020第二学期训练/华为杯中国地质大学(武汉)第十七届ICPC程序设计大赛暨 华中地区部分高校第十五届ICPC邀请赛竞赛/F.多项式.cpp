#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
int prim[maxn/5],prime_n;
bool nt_pr[maxn]={1,1};
void prime(){
    for(int i=2;i<maxn;i++){
        if(!nt_pr[i])prim[prime_n++]=i;
        for(int j=0;j<prime_n&&i*prim[j]<maxn;j++){
            nt_pr[prim[j]*i]=1;
            if(i%prim[j]==0)break;
        }
    }
}
LL n,k,p;
LL qmul(LL a,LL b){
	LL ans=0;
	while(b){
		if(b&1)ans=(ans+a)%p;
		a=(a<<1)%p,b>>=1;
	}
	return ans;
}
LL qpow(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1)ans=qmul(ans,a);
		a=qmul(a,a),b>>=1;
	}
	return ans;
}
int calc(int a,int b,int x){
	int ans=0,c=a-b;
	while(a)ans+=(a/=x);
	while(b)ans-=(b/=x);
	while(c)ans-=(c/=x);
	return ans;
}
void work(){
	LL ans=1;n<<=1;
	for(int i=0;i<prime_n;i++)
		ans=qmul(ans,qpow(prim[i],calc(n,k,prim[i])));
	printf("%lld\n",ans);
}
int main(){
	prime();
	while(~scanf("%lld%lld%lld",&n,&k,&p))work();
	return 0;
} 
