#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7,inv=5e8+4;
int main(){
	int sum=0,sum1=0,n,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),(sum+=x)%=mo,(sum1+=1ll*x*x%mo)%=mo;
	printf("%d",((1ll*sum*sum-sum1)%mo*inv%mo+mo)%mo);
	return 0;
}
