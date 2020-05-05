#include<bits/stdc++.h>
using namespace std;
int f[2019],n;
int work(){
	n=min(n,2009);
	printf("%d\n",f[n]);
	return 0;
}
int main(){
	f[0]=1;for(int i=1;i<2010;i++)f[i]=f[i-1]*i%2009;
	while(~scanf("%d",&n))work();
	return 0;
}
