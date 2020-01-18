#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
int gcd(int a,int b){return b?gcd(b,a%b):a;}
LL merge(LL l1,LL r1,LL l2,LL r2){
	return max(0ll,min(r1,r2)-max(l1,l2)+1);
}
int main(){
	int n,x,d,g,w,w1,w2;scanf("%d%d%d",&n,&x,&d),g=gcd(x,d);
	LL ans=1,l,r;
	if(1ll*d*g<0)d=-d,x=-x;
	if(!d){
		if(!x)putchar('1');
		else printf("%d",n+1);
		return 0;
	}
	if(!x)w1=1,w2=0;
	else w1=d/g,w2=x/g;
	for(int i=1;i<=n;i++){
		l=1ll*(i-1)*i/2,r=1ll*(n+n-i-1)*i/2;
		ans+=r-l+1;
		if((w=i-w1)>=0)ans-=merge(l+w2,r+w2,1ll*w*(w-1)/2,1ll*(n+n-w-1)*w/2);
	}
	printf("%lld",ans);
	return 0;
}
