#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define eps 1e-6
struct Point{
	double x,y;
}a[maxn];
int n;
bool check(long double x){
	long double l=-1e18,r=1e18,w;
	for(int i=0;i<n;i++){
		if(a[i].y-x*2>eps)return 0;
		w=sqrt(2*x*a[i].y-a[i].y*a[i].y);
		l=max(l,a[i].x-w),r=min(r,a[i].x+w);
	}
	return r-l>-eps;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=1;i<n;i++)if(a[i].y*a[i-1].y<0)return puts("-1"),0;
	for(int i=0;i<n;i++)a[i].y=abs(a[i].y);
	long double l=0,r=1e17,mid;
	while(r-l>(r/1e18)){
		mid=(l+r)/2.0;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.10Lf",l);
	return 0;
}
/*
3
1 2
0 1
2 1
*/
