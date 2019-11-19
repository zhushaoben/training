#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL ans[400],si,a[400],si1;
int work(){
	LL n,n1,m,num=0,sum=0,n2,w=1,i;si=0;scanf("%lld%lld",&n,&m);
	n2=n1=m+2;sum+=n1;ans[si++]=1;ans[si++]=n1+1;
	while(w<=n1)w<<=1;w>>=1;
	while(n2>(w+1))n2-=w,w>>=1,num++;
	for(i=2;i<=n1;i*=2)sum+=i,ans[si]=ans[(si++)-1]+i;
	ans[si]=n1+ans[(si++)-1];sum+=n1;
	while(num--)i/=2;i/=2;
	for(LL j=2;j<=i;j*=2)sum+=j,ans[si]=ans[(si++)-1]+j;
	n%=sum;
	for(int i=0;i<si;i++){
		if(n==ans[i])return puts("hyy"),0;
	}
	puts("wqy");
	return 0;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("3.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
