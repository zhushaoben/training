#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int num[N],a[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),num[a[i]]++;
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=1ll*num[i]*(num[i]-1)/2;
	for(int i=0;i<n;i++)printf("%lld\n",ans-num[a[i]]+1);
	return 0;
}
