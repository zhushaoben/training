#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double x,y,z,x1,Y1,z1,x2,y2,z2,x3,y3,z3,a,b,c;
const double PI=acos(-1.0);
double dis(double x,double y,double z,double x1,double Y1,double z1){
	return sqrt((x-x1)*(x-x1)+(y-Y1)*(y-Y1)+(z-z1)*(z-z1));
}
void work(){
	int n;scanf("%d%lf%lf%lf",&n,&x,&y,&z);
	double ma=0,mi=1e9,mi1=1e9;
	for(int i=1;i<2*n;i++){
		scanf("%lf%lf%lf",&a,&b,&c);
		if(dis(x,y,z,a,b,c)>ma)ma=dis(x,y,z,a,b,c),x1=a,Y1=b,z1=c;
		if(dis(x,y,z,a,b,c)<mi)mi1=mi,x3=x2,y3=y2,z3=z2,
		mi=dis(x,y,z,a,b,c),x2=a,y2=b,z2=c;
		else if(dis(x,y,z,a,b,c)<mi1)mi1=dis(x,y,z,a,b,c),x3=a,y3=b,z3=c;
	}
	z2-=z,x2-=x,y2-=y,z3-=z,y3-=y,x3-=x,x1-=x,Y1-=y,z1-=z;
	a=y2*z3-z2*y3,b=x3*z2-x2*z3,c=x2*y3-x3*y2;
	double h=fabs((a*x1+b*Y1+c*z1)/dis(0,0,0,a,b,c)),r=sqrt(dis(0,0,0,x1,Y1,z1)*dis(0,0,0,x1,Y1,z1)-h*h)/2;
	printf("%.6lf\n",PI*r*r*h);
}
int main(){
	int t=1;
	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
