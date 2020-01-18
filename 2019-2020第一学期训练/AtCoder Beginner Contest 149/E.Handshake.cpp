#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 100005
LL m,s[maxn*2];
int a[maxn],b[maxn*2],n;
bool check(int x){
	LL sum=0;
	for(int i=0;i<n;i++){
		if(a[i]<=x)sum+=b[x-a[i]];
		else sum+=n;
	}
	return sum>=m;
}
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		b[a[i]]++,s[a[i]]+=a[i];
	}
	for(int i=99999;~i;i--)b[i]+=b[i+1],s[i]+=s[i+1];
	int l=0,r=2e5,mid;
	LL ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	for(int i=0;i<n;i++){
		if(a[i]>l)m-=n,ans+=1ll*a[i]*n+s[0];
		else m-=b[l-a[i]],ans+=1ll*a[i]*b[l-a[i]]+s[l-a[i]];
	}
	ans+=m*(l-1);
	printf("%lld\n",ans);
	return 0;
}
