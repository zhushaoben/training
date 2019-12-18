#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn],b[maxn],c[maxn];
int main(){
	int n,ans;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	c[0]=1;for(int i=1;i<n;i++)if(a[i-1]<a[i])c[i]=c[i-1]+1;else c[i]=1;
	for(int i=n-1;~i;i--)if(a[i+1]>a[i])b[i]=b[i+1]+1;else b[i]=1;
	ans=b[0];
	for(int i=n-2;i;i--){
		if(a[i-1]<a[i+1])ans=max(ans,b[i+1]+c[i-1]);
		ans=max(ans,b[i]);
	}
	printf("%d",ans);
	return 0;
}
