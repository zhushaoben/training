#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int a[N];
LL f[N][3];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=0;i<=n;i++)f[i][0]=f[i][1]=f[i][2]=-1e18;
	f[1][0]=a[1],f[2][1]=a[2],f[3][2]=a[3],
	f[3][0]=a[3]+a[1];
	for(int i=4;i<=n;i++){
		f[i][0]=f[i-2][0]+a[i];
		f[i][1]=max(f[i-2][1],f[i-3][0])+a[i];
		f[i][2]=max(f[i-2][2],max(f[i-3][1],f[i-4][0]))+a[i];
	}
	LL ans;
	if(n&1)ans=max(f[n][2],max(f[n-1][1],f[n-2][0]));
	else ans=max(f[n][1],f[n-1][0]);
	printf("%lld",ans);
	return 0;
}
