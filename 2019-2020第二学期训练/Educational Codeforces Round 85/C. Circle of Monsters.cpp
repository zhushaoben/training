#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long LL;
LL a[N],b[N];
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld",a+i,b+i);
	LL ans=a[0],w;
	for(int i=1;i<n;i++)ans+=max(0ll,a[i]-b[i-1]);
	w=ans-max(0ll,a[1]-b[0])+a[1]-a[0]+max(0ll,a[0]-b[n-1]);
	ans=min(ans,w);
	for(int i=2;i<n;i++){
		w=w-max(0ll,a[i]-b[i-1])+a[i]-a[i-1]+max(0ll,a[i-1]-b[i-2]);
		ans=min(ans,w);
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
