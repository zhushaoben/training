#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,a[maxn],b[maxn];
void work(){
	long long ans=0;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=10;i<=1e9;i*=10){
		for(int j=0;j<n;j++)b[j]=a[j]%i;
		sort(b,b+n);
		for(int j=0;j<n;j++){
			ans+=n-(lower_bound(b,b+n,i-b[j])-b)-(b[j]+b[j]>=i);
		}
	}
	printf("%lld\n",ans/2);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
