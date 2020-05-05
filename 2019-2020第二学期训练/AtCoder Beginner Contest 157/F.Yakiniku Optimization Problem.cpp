#include<bits/stdc++.h>
using namespace std;
const int N=65;
const double eps=1e-6;
int n,k,x[N],y[N],c[N];
double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int calc(double x1,double y1,double w){
	int num=0;
	for(int i=0;i<n;i++)
		if(dis(x1,y1,x[i],y[i])<=w/c[i]+eps)num++;
	return num;
}
bool work(double x1,double y1,double w1,double x2,double y2,double w2,double w){
	double a=dis(x1,y1,x2,y2);
	if(a>w1+w2+eps)return 0;
	double co=(a*a+w1*w1-w2*w2)/(2*a*w1),l=w1*co,x3=x1+(x2-x1)/a*l,y3=y1+(y2-y1)/a*l,
	h=sqrt(w1*w1-l*l),x4=x3-(y2-y1)/a*h,y4=y3+(x2-x1)/a*h,x5=2*x3-x4,y5=2*y3-y4;
	//x4,y4;x5,y5为两圆交点 
	return calc(x4,y4,w)>=k||calc(x5,y5,w)>=k;
}
bool check(double w){
	for(int i=0;i<n;i++)if(calc(x[i],y[i],w)>=k)return 1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
			if(work(x[i],y[i],w/c[i],x[j],y[j],w/c[j],w))return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d%d%d",x+i,y+i,c+i);
	double l=0,r=1e6,mid;
	while(r-l>eps){
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.7lf",l);
	return 0;
} 
