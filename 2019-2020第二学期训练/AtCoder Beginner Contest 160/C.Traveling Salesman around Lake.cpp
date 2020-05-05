#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	int k,n,ans=1e9;scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)ans=min(ans,k-a[i+1]+a[i]);
	ans=min(ans,a[n-1]-a[0]);
	printf("%d",ans);
	return 0;
}
