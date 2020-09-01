#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p,a;
int ans[1500],si;
void work(){
	scanf("%lld",&a);
	int sum=0;si=0;
	while(a>2500-sum){
		a+=p;
		for(int i=2;i<=100;i++)
			while(a%i==0)a/=i,sum+=i,ans[si++]=i;
	}
	if(a>1)ans[si++]=a;
	printf("%d ",si);
	for(int i=0;i<si;i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int t;scanf("%lld%d",&p,&t);
	while(t--)work();
	return 0;
}
