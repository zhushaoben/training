#include<bits/stdc++.h>
using namespace std;
#define LD long double
void work(){
	LD a,b,c,x;scanf("%Lf%Lf%Lf%Lf",&a,&b,&c,&x);
	printf("%.3Lf %.3Lf %.3Lf\n",min((long double)1,a/100.0+x/900),min((long double)1,b/100.0+x/900),min((long double)1,c/100.0+x/900));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
