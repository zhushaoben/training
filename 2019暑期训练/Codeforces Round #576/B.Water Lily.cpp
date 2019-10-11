#include<bits/stdc++.h>
using namespace std;
int main(){
	long long h,l;scanf("%lld%lld",&h,&l);
	printf("%.10lf",(l*l-h*h)/double(2*h));
	return 0;
}
