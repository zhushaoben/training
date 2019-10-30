#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,x;scanf("%lf%lf%lf",&a,&b,&x);
	if(x>=a*a*b/2){
		x=a*a*b-x;x/=a*a/2;
		printf("%.8lf\n",atan(x/a)*90/asin(1));
		return 0;	
	}
	x/=a*b/2;
	printf("%.8lf\n",90-atan(x/b)*90/asin(1));
	return 0;
}
