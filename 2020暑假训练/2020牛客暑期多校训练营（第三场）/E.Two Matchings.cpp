#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=2e9;
typedef long long LL;
int a[N];LL f[N];
void work(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	f[4]=(a[4]-a[1])*2,f[6]=(a[6]-a[1])*2;f[8]=f[4]+(a[8]-a[5])*2;
	for(int i=10;i<=n;i+=2)f[i]=min(f[i-4]+(a[i]-a[i-3])*2,f[i-6]+(a[i]-a[i-5])*2);
	printf("%lld\n",f[n]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
