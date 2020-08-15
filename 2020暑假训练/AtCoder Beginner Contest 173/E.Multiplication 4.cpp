#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5,mo=1e9+7;
LL a[N],sia,sib;
int main(){
	int n,k,x;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%lld",a+i),sia+=a[i]>=0;
	LL ans=1;
	sort(a,a+n,greater<int>());
	if(!sia && k&1){
		for(int i=0;i<k;i++)(ans*=a[i])%=mo;
		return printf("%lld",ans+mo),0;
	}
	int l=0,r=n-1;
	if(k&1)ans*=a[l++];
	for(int i=k/2;i;i--){
		if(a[l]*a[l+1]>=a[r]*a[r-1])ans=ans*a[l]%mo*a[l+1]%mo,l+=2;
		else ans=ans*a[r]%mo*a[r-1]%mo,r-=2;
	}
	printf("%lld",(ans+mo)%mo);
	return 0;
}
