#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long LL;
LL a[N],bit[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++) bit[i]=bit[i/2]+1;
	sort(a,a+n,greater<LL>());
	LL x=a[0];a[n]=-1e16;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1])continue;
		if(bit[i]*(a[i]-a[i+1])<=x-a[i+1]){
			x-=bit[i]*(a[i]-a[i+1]);
		}
		else{
			x=a[i]-(x-a[i])/(bit[i]-1);
			break;
		}
	}
	printf("%lld\n",a[0]-x);
	return 0;
} 
