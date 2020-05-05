#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[105];
int main(){
	int n,ans=0,now=0;scanf("%d",&n);a[n+1]=1001;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		if(a[i-1]==a[i]-1&&a[i+1]==a[i]+1)now++;
		else ans=max(ans,now),now=0;
	}
	printf("%d",max(ans,now));
	return 0;
}
