#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
#define LL long long
LL a[maxn+5];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);for(int i=m;i<n;i++)a[i]+=a[i-m];
	for(int i=0;i<n;i++)printf("%lld ",(a[i]+=i-1>=0?a[i-1]:0));
	return 0;
}
