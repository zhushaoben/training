#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=305;
int main(){
	int n;
	LL a1,a2,x,sum=0;scanf("%d%lld%lld",&n,&a1,&a2);
	for(int i=2;i<n;i++)scanf("%lld",&x),sum^=x;
	LL w=a1+a2-sum,ans=0;
	if(w<0||w%2||((w>>=1)&sum)||w>a1)return puts("-1"),0;
	ans=w;
	for(int i=63;i>=0;i--){
		if(((1ll<<i)&sum)&&ans+(1ll<<i)<=a1)ans+=(1ll<<i);
	}
	if(ans==0)return puts("-1"),0;
	printf("%lld\n",a1-ans);
	return 0;
} 
