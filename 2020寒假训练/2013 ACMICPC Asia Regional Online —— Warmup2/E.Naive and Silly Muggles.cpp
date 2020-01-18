#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define eps 1e-5
double dist(double x,double y){
	return x*x+y*y;
}
void work(){
	double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	double a=dist(x1-x2,y1-y2)/4,b=dist(x1-x3,y1-y3)/4,c=dist(x2-x3,y2-y3)/4;bool fl;
	if(a>b+c){
		x5=(x1+x2)/2.0,y5=(y1+y2)/2.0;
		fl=dist(x5-x4,y5-y4)-eps>a;
	}
	else if(b>a+c){
		x5=(x1+x3)/2.0,y5=(y1+y3)/2.0;
		fl=dist(x5-x4,y5-y4)-eps>b;
	}
	else if(c>a+b){
		x5=(x3+x2)/2.0,y5=(y3+y2)/2.0;
		fl=dist(x5-x4,y5-y4)-eps>a;
	}
	else{
		x5=(double)(x1*x1*(y2-y3)+x2*x2*(y3-y1)+x3*x3*(y1-y2)-(y1-y2)*(y2-y3)*(y3-y1))/(2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
		y5=-(double)(y1*y1*(x2-x3)+y2*y2*(x3-x1)+y3*y3*(x1-x2)-(x1-x2)*(x2-x3)*(x3-x1))/(2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
		fl=dist(x5-x4,y5-y4)-eps>dist(x5-x1,y5-y1);
	}
	if(fl)puts("Safe");
	else puts("Danger");
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
