#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n;scanf("%d",&n);
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*(i+n/i*i)*(n/i)/2;
	}
	printf("%lld",ans);
	return 0;
}
