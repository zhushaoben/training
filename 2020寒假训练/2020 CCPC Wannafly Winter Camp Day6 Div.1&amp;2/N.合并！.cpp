#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
#define LL long long
int a[maxn];
int main(){
	int n,sum=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),sum+=a[i];
	LL ans=0;
	for(int i=0;i<n;i++)ans+=1ll*(sum-a[i])*a[i];
	printf("%lld",ans/2);
	return 0;
} 
