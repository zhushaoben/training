#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],fac[10],n;
int calc(int a[],int l){
	if(l>=n)return 0;
	for(int i=l+1;i<n;i++)if(a[i]>a[l])a[i]--;
	return a[l]*fac[n-l-1]+calc(a,l+1);
}
int main(){
	scanf("%d",&n);
	fac[0]=1;for(int i=1;i<10;i++)fac[i]=fac[i-1]*i;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	printf("%d",abs(calc(a,0)-calc(b,0)));
	return 0;
}
