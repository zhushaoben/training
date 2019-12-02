#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mo 998244353
LL Pow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int main(){
	LL n,n1,n2,ans;scanf("%lld",&n),n1=sqrt(n),n2=n%mo;
	ans=(-(n2*(n2+1)%mo*(2*n2+1)%mo)+(n1*(n1+1)%mo*(2*n1+1)%mo))*Pow(6,mo-2)%mo;ans=(ans%mo+mo)%mo;
	(ans+=((n+1)%mo)*((n-n1)%mo)%mo*((n+n1+1)%mo)%mo*Pow(2,mo-2)%mo)%=mo;
	for(int i=2;i<=n1;i++){
		LL x=i,w=0,j=1;
		while(x*i<=n)(w+=j*(x*i-x)%mo)%=mo,j++,x*=i;
		(w+=(n-x+1)*j%mo)%=mo;
		(ans+=w*i)%=mo;
	}
	printf("%lld\n",ans);
	return 0;
}
