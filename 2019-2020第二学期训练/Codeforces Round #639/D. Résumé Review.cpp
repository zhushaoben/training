/*ab-b^3
(b-1)a-(b-1)3
ab-a-b3+3b2-3b+1
-a+3b^2-3b+1*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long LL;
int n,a[N],b[N];LL k,w;
inline LL calc(int i,LL x){return a[i]-3*x*x+3*x-1;}
bool check(LL x){
	LL l,r,mid;//a-3b*(b-1)-1>=x b=[1,a[i]]
	w=0;
	for(int i=0;i<n;i++){
		l=1,r=a[i];
		while(l<=r){
			mid=(l+r)>>1;
			if(calc(i,mid)>=x)l=mid+1;
			else r=mid-1;
		}
		w+=(b[i]=r);
	}
	return w>=k;
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	LL l=-3e18,r=2e9,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	check(r);w-=k;
	for(int i=0;i<n;i++)printf("%d ",b[i]-((calc(i,b[i])==r&&w)?(--w,1):0));
	return 0;
}
