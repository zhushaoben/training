#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[20];
void work(){
	LL n,n1,n2,d=1;int s,sum=0;scanf("%lld%d",&n,&s),n1=n;
	while(n)sum+=n%10,n/=10;n=n1;
	if(sum<=s){puts("0");return;}
	for(int i=0;;i++){
		if((n1/d)%10!=0)n1+=(10-(n1/d)%10)*d;
		sum=0;n2=n1;while(n1)sum+=n1%10,n1/=10;n1=n2;
		if(sum<=s){printf("%lld\n",n1-n);return;}
		d*=10;
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
