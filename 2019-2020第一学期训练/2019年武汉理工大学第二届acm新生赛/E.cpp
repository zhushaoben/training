#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL ans[400],si,a[400],si1;
int work(){
	LL n,n1,m,num=0,sum=0,num1=0,n2;si1=si=0;scanf("%lld%lld",&n,&m);
	n1=m+2;n2=n1;sum+=n1;ans[si++]=1;ans[si++]=n1+1;
	while(n2)a[si1++]=(n2&1),n2>>=1;
	int pre=1;
	for(int i=1;i<si1;i++){
		if(pre==0&&a[i]==0)num--;
		if(a[i]==1)num++,num1++;
		pre=a[i];
	}
	LL i;
	if(num1-(a[0])==1)num=1;
	else num=max(num,2ll);
	for(i=2;i<=n1;i*=2)sum+=i,ans[si]=ans[(si++)-1]+i;
	ans[si]=n1+ans[(si++)-1];sum+=n1;
	while(num--)i/=2;
	for(LL j=2;j<=i;j*=2)sum+=j,ans[si]=ans[(si++)-1]+j;
	n=n%sum;
	for(int i=0;i<si;i++){
		if(n==ans[i])return puts("hyy"),0;
	}
	puts("wqy");
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
