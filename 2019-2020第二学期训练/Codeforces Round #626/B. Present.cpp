#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int a[N];
int main(){
	int n,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=25;~i;i--){
		sort(a,a+n);
		int w=0,s=1<<i,w1;
		for(int j=0;j<n;j++){
			a[j]<<=1;if((a[j]>=s&&a[j]<2*s)||(a[j]>=3*s))w--;a[j]>>=1;
			w-=lower_bound(a,a+n,max(0,s-a[j]))-a;
			w+=lower_bound(a,a+n,max(0,2*s-a[j]))-a;
			w-=lower_bound(a,a+n,3*s-a[j])-a;
			w+=n;
		}w/=2;
		if(w&1)ans|=(1<<i);
		for(int j=0;j<n;j++)if(a[j]&(1<<i))a[j]^=(1<<i);
	}
	printf("%d",ans);
	return 0;
}
