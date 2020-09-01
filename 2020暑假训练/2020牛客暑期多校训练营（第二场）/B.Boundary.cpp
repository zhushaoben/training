#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const long double eps=1e-12;
struct Point{
	int x,y;
}a[N];
long double getb(Point a,Point b){a.x-=b.x,a.y-=b.y;return (long double)(a.x*b.y-a.y*b.x)/(a.x*b.x+a.y*b.y);}
double b[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	int ans=0,w,si;
	for(int i=0;i<n;i++){
		si=0;
		for(int j=0;j<n;j++){
			if(a[i].x*a[j].y-a[j].x*a[i].y<=0)continue;
			b[++si]=getb(a[i],a[j]);
		}
		sort(b+1,b+si+1);w=1;
		for(int j=1;j<=si;j++){
			if(b[j]-b[j-1]>eps)ans=max(ans,w),w=2;
			else w++;
		}
		ans=max(ans,w);
	}
	printf("%d",ans);
	return 0;
}
