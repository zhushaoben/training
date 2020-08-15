#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0;long long x;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		while(x)ans+=(x%256==97),x>>=8;
	}
	printf("%d\n",ans);
	return 0;
}
