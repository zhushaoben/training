#include<bits/stdc++.h>
using namespace std;
#define LL long long
void work(){
	int n,x;scanf("%d",&n);
	LL sum=0,ma=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x),x--;
		sum+=x,ma=max(ma,1ll*x);
	}
	if(sum>=ma*(n-1))printf("%lld\n",n*ma-sum);
	else puts("-1");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
