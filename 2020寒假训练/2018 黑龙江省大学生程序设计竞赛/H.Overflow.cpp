#include<bits/stdc++.h>
using namespace std;
#define eps 1e-5
#define maxn 10005
int n,s,h,v;
double l[maxn],p[maxn];
bool check(double h){
	double v1=v;
	for(int i=0;i<n;i++){
		v1+=l[i]*l[i]*min(h,l[i]*p[i]);
	}
	return v1>=s*h;
}
void work(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lf%lf",l+i,p+i),p[i]=min(p[i],1.0);
	scanf("%d%d%d",&s,&h,&v);
	double l=v/s,r=h,mid;
	while(r-l>eps){
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.2lf\n",l);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
