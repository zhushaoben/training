#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL calc(LL h){
	if(h==1)return 1;
	return calc(h/2)*2+1;
} 
int main(){
	LL h;scanf("%lld",&h);
	printf("%lld",calc(h));
	return 0;
} 
