#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		long long x=gcd(a,b),y=x*b,z=a*a-4ll*y,k;
		if(z<0){puts("No Solution");continue;}
		k=sqrt(z);
		if(k*k!=z||k>=a||(a-k)%2){puts("No Solution");continue;}
		printf("%d %d\n",(a-k)/2,(a+k)/2);
		
	}
}
