#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
const double PI=acos(-1);
void work(){
	double n,r,l,h,w;scanf("%lf%lf%lf",&n,&r,&l);
	if(!n||!r){printf("%.10lf\n",0);return;}
	if(!l){printf("%.10lf\n",PI*r*r);return;}
	if(2*r-l<eps){printf("%.10lf\n",n*PI*r*r);return;}
	h=sqrt(r*r-l*l/4)*2,w=atan(h/l);
	printf("%.10lf\n",n*PI*r*r-(n-1)*(2*w*r*r-h*l/2));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
