#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m,k;
LL calc(int l,int r){
	return 1ll*(l+r)*(r-l+1)/2;
}
void work(){
	k/=2;LL ans=0;
	for(int i=1;i<=n&&i<k;i++){
		ans+=(n-i+1)*calc(m-min(k-i,m)+1,m);
	}
	printf("%lld\n",ans);
}
int main(){
	while(~scanf("%d%d%d",&n,&m,&k))work();
	return 0;
}
