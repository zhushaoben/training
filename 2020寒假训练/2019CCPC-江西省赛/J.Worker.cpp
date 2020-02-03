#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define LL long long
int a[maxn],n;LL m;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
int work(){
	LL sum=0,num=1;
	for(int i=0;i<n;i++)scanf("%d",a+i),num=lcm(num,a[i]);
	for(int i=0;i<n;i++)sum+=(a[i]=num/a[i]);
	if(m%sum)return puts("No"),0;
	puts("Yes");
	for(int i=0;i<n-1;i++)printf("%lld ",m/sum*a[i]);
	printf("%lld\n",m/sum*a[n-1]);
	return 0;
}
int main(){
	while(~scanf("%d%lld",&n,&m))work();
	return 0;
}
