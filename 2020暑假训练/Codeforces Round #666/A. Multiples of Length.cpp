#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(n==1)return puts("1 1\n0\n1 1\n0"),printf("1 1\n%d\n",-a[1]),0;
	else{
		printf("%d %d\n",1,n-1);
		for(int i=1;i<n;i++)printf("%lld ",1ll*a[i]*(n-1));
		puts("");
		printf("%d %d\n%lld\n",n,n,1ll*(n-1)*a[n]);
		printf("%d %d\n",1,n);
		for(int i=1;i<=n;i++)printf("%lld ",-1ll*n*a[i]);
		puts("");
	}
	return 0;
}
