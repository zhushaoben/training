#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n;scanf("%d",&n);
	ll x,w=0;
	for(int i=0;i<n;i++){
		scanf("%I64d",&x);
		w=gcd(x,w);
	}
	int w1=sqrt(w),ans=0;
	for(int i=1;i<=w1;i++){
		if(w%i==0)ans+=2;
	}
	if(1ll*w1*w1==w)ans--;
	printf("%d\n",ans);
	return 0;
}
