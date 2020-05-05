#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
int calc(int l,int r){
	return 1ll*(r+l)*(r-l+1)/2%mo;
}
int main(){
	int n,k,ans=0;scanf("%d%d",&n,&k);
	for(int i=k;i<=n+1;i++)
		(ans+=(calc(n-i+1,n)-calc(0,i-1)+1)%mo)%=mo;
	printf("%d",(ans+mo)%mo);
	return 0;
}
