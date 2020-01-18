#include<bits/stdc++.h>
using namespace std;
#define maxn 305
#define LL long long
struct Point{
	int x,y,vx,vy;
}a[maxn];
int n;
double dist(double x,double y){
	return sqrt(x*x+y*y);
}
double calc(double t){
	double ma=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			ma=max(ma,dist(a[i].x-a[j].x+(a[i].vx-a[j].vx)*t,a[i].y-a[j].y+(a[i].vy-a[j].vy)*t));
		}
	}
	return ma;
}
void work(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].vx,&a[i].vy);
	double l=0,r=1e5,midl,midr;
	while(r-l>1e-5){
		midl=l+(r-l)/3,midr=r-(r-l)/3;
		if(calc(midl)<calc(midr))r=midr;
		else l=midl;
	}
	printf("%.2lf %.2lf\n",r,calc(r));
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
