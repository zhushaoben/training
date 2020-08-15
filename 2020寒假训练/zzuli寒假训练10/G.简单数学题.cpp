#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mo=1e9+7;
LL Power(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int main(){
	LL n;
	while(~scanf("%lld",&n)){
		LL ans=0;
		for(int i=1;i<=n;i++){
			(ans+=Power(2,i-1)*i%mo)%=mo;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
