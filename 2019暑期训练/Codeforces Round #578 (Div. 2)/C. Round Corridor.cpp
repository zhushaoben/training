#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	ll n,m,q,c,d;scanf("%lld%lld%lld",&n,&m,&q);
	ll x1,y1,x2,y2;c=n/gcd(n,m),d=m/gcd(n,m);
	for(int i=0;i<q;i++){
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		if(x1==2)y1=(y1-1)/d;else y1=(y1-1)/c;
		if(x2==2)y2=(y2-1)/d;else y2=(y2-1)/c;
		if(y1==y2)puts("YES");
		else puts("NO");
	}
	return 0;
}
