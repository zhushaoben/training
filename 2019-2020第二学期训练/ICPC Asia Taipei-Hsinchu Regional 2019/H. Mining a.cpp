#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void work(){
	int n,n1;scanf("%d",&n),n1=n;
	LL ans=0,w;
	for(int i=1;i*i<=n;i++){
		if(n%i)continue;
		int x=n/i;
		w=1ll*n*(n+i);w/=gcd(w,i);
		ans=max(ans,w^(n+i));
		w=1ll*n*(n+x);w/=gcd(w,x);
		ans=max(ans,w^(n+x));
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
