#include<bits/stdc++.h>
using namespace std;
#define maxn 400005
int a[maxn];
void work(){
	int n,i,A=1,b=0,c=0;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);n=n/2+1;
	for(i=2;i<n;i++,A++)if(a[i]!=a[i-1])break;
	for(;i<n;i++,b++)if(a[i]!=a[i-1]&&b>A)break;
	for(;i<n;i++,c++)if(a[i]==a[n])break;
	if(A<b&&A<c)printf("%d %d %d\n",A,b,c);
	else puts("0 0 0");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
