#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n;scanf("%d",&n);
	LL ans=1,x,inf=1e18,fl=1,fl1=1;
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		if(!x)fl1=0;
		if(fl&&(x>inf/ans||ans*x>inf))fl=0;
		ans*=x;
	}
	if(!fl1||fl)printf("%lld",ans);
	else puts("-1");
	return 0;
}
