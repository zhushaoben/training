#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,d,x,y,ans=0;
	scanf("%lld%lld",&n,&d);d*=d;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&x,&y);
		ans+=(x*x+y*y<=d);
	}
	printf("%d",ans);
	return 0;
}
