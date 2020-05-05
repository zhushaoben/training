#include<bits/stdc++.h>
using namespace std;
/*
a+b+2gen(ab)<c
4ab<(c-a-b)^2
*/ 
typedef long long LL;
int main(){
	LL a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
	if(4*a*b<(c-a-b)*(c-a-b)&&a+b<c)puts("Yes");
	else puts("No");
	return 0;
}
