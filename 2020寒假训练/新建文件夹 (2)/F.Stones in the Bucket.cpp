#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];
void work(){
	int n;scanf("%d",&n);long long sum=0,ans=0;
	for(int i=0;i<n;i++)scanf("%d",a+i),sum+=a[i];
	sum=sum/n;
	for(int i=0;i<n;i++)ans+=max(0ll,a[i]-sum);
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
