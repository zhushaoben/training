#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	if(!k)return printf("%d",a[0]==1?-1:1),0;
	if(a[k]==a[k-1])return puts("-1"),0;
	printf("%d",a[k-1]);
	return 0;
}
