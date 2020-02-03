#include<bits/stdc++.h>
using namespace std;
int h[200005];
int main(){
	int n,k;long long ans=0;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",h+i),h[i]=-h[i];
	sort(h,h+n);
	for(int i=k;i<n;i++)ans-=h[i];
	printf("%lld",ans);
	return 0;
} 
