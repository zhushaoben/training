/*
if x,y are coprime, a,b are also coprime
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int a,b,x,y,g,dif,c;
	while(~scanf("%d%d",&a,&b)){
		g=gcd(a,b);a/=g,b/=g;
		c=a*a-4*b;dif=sqrt(c);
		if(c<0||dif*dif!=c||(dif+a)%2){puts("No Solution");continue;}
		y=(dif+a)/2*g,x=(a-dif)/2*g;
		printf("%d %d\n",x,y);
	}
	return 0;
} 
