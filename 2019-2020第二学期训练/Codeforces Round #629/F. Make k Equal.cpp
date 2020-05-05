#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
int a[N];LL b[N],c[N];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);sort(a,a+n);
	LL w=0,ans=1e18;
	for(int i=1;i<n;i++)b[i]=b[i-1]+1ll*(i)*(a[i]-a[i-1]);
	for(int i=n-2;~i;i--){
		c[i]=c[i+1]+1ll*(n-i-1)*(a[i+1]-a[i]);
	}
	for(int i=0;i<n;i++){
		if(!i||a[i]==a[i-1])w++;
		else w=1;
		if(w>=k){ans=0;break;}
		if(i+1>=k)ans=min(ans,b[i]-(i+1-k));
		if(n-i+w-1>=k)ans=min(ans,c[i]-(n-i-1+w-k));
		ans=min(ans,b[i]+c[i]-(n-k));
	}
	printf("%lld",ans);
	return 0;
}
