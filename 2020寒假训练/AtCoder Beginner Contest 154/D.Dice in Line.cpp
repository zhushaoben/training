#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	int n,k,sum=0,ans=0;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<k;i++)sum+=a[i];
	ans=sum;for(int i=k;i<n;i++)sum+=a[i]-a[i-k],ans=max(ans,sum);
	printf("%.10lf",(ans+k)/2.0);
	return 0;
}
