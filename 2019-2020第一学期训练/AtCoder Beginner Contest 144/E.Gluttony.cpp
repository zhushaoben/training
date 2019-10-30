#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
#define LL long long
int a[maxn+5],f[maxn+5],n; LL k;
bool check(LL x){
	LL ans=0;
	for(int i=0;i<n;i++){
		ans+=max(0ll,a[i]-x/f[i]);
	}
	return ans<=k;
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",f+i);
	sort(f,f+n);sort(a,a+n,greater<int>());
	LL l=0,r=1e12,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
