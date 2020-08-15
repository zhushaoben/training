#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int a[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n,greater<int>());
	LL ans=a[0];
	for(int i=n/2-1;i;i--)ans+=a[i]<<1;
	if(n&1)ans+=a[n/2];
	printf("%lld\n",ans);
	return 0;
}
