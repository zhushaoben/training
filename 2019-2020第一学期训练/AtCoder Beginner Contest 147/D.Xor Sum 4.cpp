#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mo 1000000007
int sum[60];
int main(){
	LL x,ans=0;int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		for(int j=0;j<60;j++)if(x&(1ll<<j))sum[j]++;
	}
	for(int i=0;i<60;i++)ans+=(1ll<<i)%mo*sum[i]%mo*(n-sum[i])%mo;
	printf("%d",ans%mo);
	return 0;
}
