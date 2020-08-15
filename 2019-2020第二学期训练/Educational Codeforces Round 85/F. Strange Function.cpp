#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],p[N],b[N];
long long f[N];
int main(){
	int n,m;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",p+i);
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d",b+i);
	f[1]=1e18;
	for(int i=0;i<n;i++){
		int x=lower_bound(b,b+m,a[i])-b+1;
		f[0]+=p[i];f[p[i]<0?m+1:x]-=p[i];
		if(b[x-1]==a[i]&&f[x]+p[i]>0)f[x+1]+=f[x]+p[i],f[x]=-p[i];
	}
	for(int i=1;i<=m;i++)f[i]+=f[i-1];
	if(f[m]<1e17)puts("YES"),printf("%lld\n",f[m]);
	else puts("NO");
	return 0;
} 
