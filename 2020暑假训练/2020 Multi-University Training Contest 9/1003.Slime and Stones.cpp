#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,k;scanf("%d%d%d",&a,&b,&k);
	if(a>b)swap(a,b);
	if((b-a)%(k+1)){puts("1");return;}
	int k1=(b-a)/(k+1);
	long long temp=(long double)k1*(long double)(1.0-k+sqrt(1ll*(k+1)*(k+1)+4)/(2.0));
	printf("%d\n",a!=temp);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
