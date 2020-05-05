#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
int a[N],b[N];
LL k,s1,s2,s3;
bool check(LL x){
	LL ans=0;
	if(x>=0){
		ans+=s3*(s1+s2)+s3*(s3-1)/2+s1*s2;
		int r=s1-1;
		for(int i=0;i<r;i++){
			while(1ll*a[i]*a[r]>x)r--;
			if(i>=r)break;
			ans+=r-i; 
		}
		r=s2-1;
		for(int i=0;i<r;i++){
			while(1ll*b[i]*b[r]>x)r--;
			if(i>=r)break;
			ans+=r-i;
		}
	}
	else{
		x=-x;
		int l=0;
		for(int i=s2-1;i>=0;i--){
			while(1ll*a[l]*b[i]<x&&l<s1)l++;
			ans+=s1-l;
		}
	}
	return ans>=k;
}
int main(){
	int n,x;LL l=-2e18,r=2e18,mid;scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x>0)a[s1++]=x;
		else if(x<0)b[s2++]=-x;
		else s3++;
	}
	sort(a,a+s1),sort(b,b+s2);
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}
