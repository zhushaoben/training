#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn];
int main(){
	int n,ans=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		if(a[i]==0&&a[i-1]==1&&a[i+1]==1)ans++,a[i+1]=0;
	}
	printf("%d",ans);
	return 0;
}
