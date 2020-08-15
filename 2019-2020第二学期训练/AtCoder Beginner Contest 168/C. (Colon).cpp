#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
int main(){
	int a,b,h,m;scanf("%d%d%d%d",&a,&b,&h,&m),m+=h*60;
	double A=PI*m/360,B=PI*m/30;
	printf("%.10lf",sqrt(a*a+b*b-2*cos(A-B)*a*b));
	return 0;
}
