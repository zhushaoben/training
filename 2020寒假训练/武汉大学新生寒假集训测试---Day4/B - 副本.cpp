#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
struct Point{
	double x,y;
}a,b,c,o;
double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double dist(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool line(Point p1,Point p2,Point p3){
	int w=0;
	if(p2.x==p1.x)w++;if(p2.x==p3.x)w++;
	if(w==2)return 1;if(w)return 0;
	double k1=(p2.y-p1.y)/(p2.x-p1.x),k2=(p3.y-p2.y)/(p3.x-p2.x);
	return fabs(k1-k2)<eps;
}
bool work(Point p1,Point p2,Point p3,double &r){
	if(line(p1,p2,p3))
		return false;
	double  x1=p1.x,x2=p2.x,x3=p3.x,y1=p1.y,y2=p2.y,y3=p3.y
	,a=dist(p1,p2),b=dist(p1,p3),c=dist(p2,p3),p=(a+b+c)/2,S=sqrt(p*(p-a)*(p-b)*(p-c));
	r=a*b*c/(4*S);
	double t1=x1*x1+y1*y1,t2=x2*x2+y2*y2,t3=x3*x3+y3*y3,P=x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2;
	o.x=(t2*y3+t1*y2+t3*y1-t2*y1-t3*y2-t1*y3)/P/2;
	o.y=(t3*x2+t2*x1+t1*x3-t1*x2-t2*x3-t3*x1)/P/2;
	return true;
}
int main(){
	int n;double x1,y1,x2,y2;scanf("%d",&n);
	if(n==1){
		scanf("%lf%lf",&x1,&y1);
		printf("%lf",fabs(y1/2));
		return 0;
	}
	if(n==2){
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		if(fabs(x1-x2)<eps||y1*y2<0)return puts("-1"),0;
		double a=dist(x1,y1,x2,y2)/2,b=(y1+y2)*a/fabs(x1-x2),r=(b*b+a*a)/2/b;
		if(r-b>eps)return puts("-1"),0;
		printf("%lf",r);
		return 0;
	}
	scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	double r;
	if(!work(a,b,c,r)||fabs(fabs(o.y)-r)>eps)return puts("-1"),0;
	for(int i=3;i<n;i++){
		scanf("%lf%lf",&a.x,&a.y);
		if(fabs(dist(a,o)-r)>eps)return puts("-1"),0;
	}
	printf("%lf",r);
	return 0;
}
/*
3
1 2
0 1
3 1
*/
