#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100;
int a[N];
int main(){
	LL n=0,num=1000,num1=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);a[n]=0;
	for(int i=0;i<n;i++){
		if(a[i]<a[i+1])num1+=num/a[i],num%=a[i];
		else num+=num1*a[i],num1=0;
	}
	printf("%lld",num);
	return 0;
}
