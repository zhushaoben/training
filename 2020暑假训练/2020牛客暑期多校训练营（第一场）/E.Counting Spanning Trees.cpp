#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,mo,a[N],b[N],fl;
void work(){
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]++;
	for(int i=m;i;i--)b[i]+=b[i+1];
	long long ans=1;fl=1;
	for(int i=1;i<=n;i++)if(a[i]*fl==m)fl=0;else ans=ans*a[i]%mo;
	for(int i=2;i<=m;i++)ans=ans*b[i]%mo,b[i]=0;b[1]=0;
	printf("%lld\n",ans);
}
int main(){
	while(~scanf("%d%d%d",&n,&m,&mo))work();
	return 0;
} 
