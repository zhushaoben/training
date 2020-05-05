#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int n,k,x,ma=0,ans=0;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&x),a[x]++;
	for(int i=1;i<=100;i++)ma=max(ma,a[i]);
	ma+=k-(ma-1)%k-1;
	for(int i=1;i<=100;i++)if(a[i])ans+=ma-a[i];
	printf("%d",ans);
	return 0;
}
