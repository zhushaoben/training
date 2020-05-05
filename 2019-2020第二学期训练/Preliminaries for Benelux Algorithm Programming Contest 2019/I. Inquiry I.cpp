#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long LL;
int a[N];
int main(){
	int n,sum=0;scanf("%d",&n);
	long long ans=0,w=0;
	for(int i=0;i<n;i++)scanf("%d",a+i),sum+=a[i];
	for(int i=0;i<n;i++){
		sum-=a[i],w+=a[i]*a[i];
		ans=max(ans,sum*w);
	}
	printf("%lld",ans);
	return 0;
} 
