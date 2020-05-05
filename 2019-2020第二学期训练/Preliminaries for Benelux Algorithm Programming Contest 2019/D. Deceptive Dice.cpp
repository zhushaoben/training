#include<bits/stdc++.h>
using namespace std;
double f[200];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		int x=f[i-1];
		f[i]=(f[i-1]*x+(x+1+n)*(n-x)/2)/n;
	}
	printf("%.10lf",f[k]);
	return 0;
}
