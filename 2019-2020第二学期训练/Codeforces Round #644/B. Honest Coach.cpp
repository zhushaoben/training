#include<bits/stdc++.h>
using namespace std;
int a[200];
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	int ans=2e3;
	for(int i=1;i<n;i++)ans=min(ans,a[i]-a[i-1]);
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
