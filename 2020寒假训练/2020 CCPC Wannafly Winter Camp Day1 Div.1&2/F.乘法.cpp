#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
int a[maxn],b[maxn],n,m;
bool check(LL x){
	LL num=0;
}
int main(){
	LL k;scanf("%d%d%lld",&n,&m,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int j=0;j<m;j++)scanf("%d",b+i);
	sort(b,b+m);sort(a,a+n);
	LL l=-1e12,r=1e12,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}
