#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]-a[i-1]>1)a[i]--,ans++;
		else if(a[i]-a[i-1]==1)ans++;
		else if(a[i]==a[i-1])a[i]++,ans++;
		else a[i]=a[i-1];
	}
	printf("%d\n",ans);
	return 0;
}
