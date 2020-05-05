#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
int n,a[maxn];LL k;
bool check(LL x){
	LL num=0,sum=0;int r=0;
	for(int i=0;i<n;i++){
		while(r<n&&sum+a[r]<=x)sum+=a[r++];
		num+=r-i;sum-=a[i];
	}
	return num>=k;
}
int main(){
	LL l=0,r=1e14,mid;scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
} 
