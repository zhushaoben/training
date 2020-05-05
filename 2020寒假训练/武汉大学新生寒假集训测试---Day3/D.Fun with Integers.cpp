#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL calc(int x){
	if(x>=2)return 1ll*(2+x)*(x-1)/2;
	else return 0;
}
int main(){
	int n;scanf("%d",&n);
	LL ans=0;
	for(int i=2;i<=n;i++){
		ans+=calc(n/i);
	}
	printf("%lld",ans*4);
	return 0;
}
