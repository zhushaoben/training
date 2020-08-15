#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const double eps=1e-6;
double f[N];
int main(){
	f[0]=1,f[1]=0.5;
	for(int i=2;i<=1e5;i++)f[i]=1.0/(i+1)*(1+f[i-2]*(i-1));
	int n;
	while(~scanf("%d",&n)){
		if(f[n]-0.5>eps)puts("1");
		else if(0.5-f[n]>eps)puts("2");
		else puts("0");
	}
	return 0;
} 
